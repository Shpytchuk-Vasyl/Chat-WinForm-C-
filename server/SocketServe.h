#pragma once
#undef UNICODE

#define WIN32_LEAN_AND_MEAN
#include "MailSlotsSender.h"
#include "../Client/TypeRequest.h"
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <vector>
#include <execution>
#include <algorithm>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
#include "CChat.h"
#include "DbConector.h"
#include "CUser.h"
// #pragma comment (lib, "Mswsock.lib")

class SockedThread {
    SOCKET ClientSocket = INVALID_SOCKET;
    std::vector<SockedThread>* clients;
    std::thread* myThread = nullptr;
    CDatabase* db = nullptr;
    std::vector<int>* online = nullptr;
    std::vector<std::pair<int, MailSlotsSender>> *connection_list = nullptr;
    CChat current_chat;
    int current_user_id = 0;
    bool isActive = true;
    std::vector<std::pair<int, SOCKET>>::iterator it;
    int userId = 0;

public:
    SockedThread(SOCKET clientSocket, CDatabase* db, std::vector<int>* online, std::vector<std::pair<int, MailSlotsSender>>* connectoin_list, std::vector<SockedThread> *clients) {
        this->ClientSocket = clientSocket;
        this->db = db;
        this->online = online;
        this->clients = clients;
        this->connection_list = connectoin_list;
        if (clientSocket == INVALID_SOCKET) 
            throw std::exception();
                                                                                            // доініціалізувати поля ( поки немає звідки )
    }
    int get_userId() {
        return current_user_id;
    }
    CChat get_curent_chat() {
        return current_chat;
    }
    bool isOnline(int id) {
        auto it = std::find(online->begin(), online->end(), id);                //треба буде затестити 
        return it != online->end();
    }

    bool isChatOpened(CChat chat , int userid) {
        if (isOnline(userid)) {
            for (auto cli : *clients) {
                if (cli.get_userId() == userId) {
                    if (cli.get_curent_chat() == chat) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return false;

    }

        static void Run(SockedThread socketThread) {

        // socketThread.recvbuf[0] = 0;
        do {
            char recvbuf[DEFAULT_BUFLEN] = "";
            int recvbuflen = DEFAULT_BUFLEN;
         
            int iResult = 0;
            int iSendResult = 0;
            int other_user_id = 0;
            std::vector<CMessage>  msgs;
            std::vector<CChat>  chats;
            std::vector<CUser>  users;
            CUser  user_res;
            CChat chat;
            CMessage msg;
            iResult = recv(socketThread.ClientSocket,
                recvbuf,
                sizeof(recvbuf),
                0);

            if (iResult > 0) {
                //printf("Socked %d :Bytes received: %d\n", socketThread.ClientSocket, iResult);
                TypeRequest type = (TypeRequest)std::atoi(recvbuf);
                memset(recvbuf, 0, recvbuflen);
                // отримання значення TypeRequest

                switch (type) {
                case TypeRequest::SECCESS://не може поідеї
                    // Обробка успішного виконання
                    break;

                case TypeRequest::REGISTER_REQUEST:
                    // Обробка запиту на реєстрацію

                    if (socketThread.ClientSocket == INVALID_SOCKET)
                        throw std::exception();

                    iResult = recv(socketThread.ClientSocket,
                        recvbuf,
                        recvbuflen,
                        0);
                    user_res = *(CUser*)recvbuf;
                    try {
                        socketThread.db->add_user(user_res);
                        socketThread.current_user_id = socketThread.db->get_user_id(user_res);

                        socketThread.online->emplace_back(socketThread.current_user_id, MailSlotsSender(user_res.getName()));
                        iSendResult = send(socketThread.ClientSocket, std::to_string(TypeRequest::SECCESS).c_str(), sizeof(SECCESS), 0);
                    }
                    catch (sql::SQLException& e) {
                        iSendResult = send(socketThread.ClientSocket, std::to_string(TypeRequest::ERR).c_str(), sizeof(ERR), 0);
                    }
                    break;

                case TypeRequest::START_REQUEST://отримуємо всі чати


                    iResult = recv(socketThread.ClientSocket,
                        recvbuf,
                        recvbuflen,
                        0);
                    user_res = *(CUser*)recvbuf;
                    socketThread.current_user_id = socketThread.db->get_user_id(user_res);// зробити функцію для  перевірки чи є юзер з заданим імям та паролем 
                    socketThread.online->emplace_back(socketThread.current_user_id, MailSlotsSender(user_res.getName()));

                    // std::vector<CChat> chats = socketThread.db->get_chats_with_user(socketThread.current_user_id);
                    // цього не треба, бо я й так буду знати що сервер не доступний
                    //iSendResult = send(socketThread.ClientSocket, std::to_string(TypeRequest::SECCESS).c_str(), sizeof(SECCESS), 0);
                    if (iSendResult == SOCKET_ERROR) {
                        printf("send failed with error: %d\n", WSAGetLastError());
                        closesocket(socketThread.ClientSocket);
                        socketThread.isActive = false;
                        return;
                    }
                    break;
                case TypeRequest::GET_MESSAGE://не може
                    // Обробка отримання повідомлення
                    break;

                case TypeRequest::SEND_MESSAGE:             // треба дивитись який чат відкритий в іншого юзера 
                    iResult = recv(socketThread.ClientSocket,
                        recvbuf,
                        recvbuflen,
                        0);
                    other_user_id = 0;
                    if (socketThread.current_user_id == socketThread.current_chat.getUser2Id()) {
                        other_user_id = socketThread.current_chat.getUser1Id();
                    }
                    else {
                        other_user_id = socketThread.current_chat.getUser2Id();
                    }
                     msg = *(CMessage*)recvbuf;
                    socketThread.db->add_message(msg);
                    if (socketThread.isOnline(other_user_id)&& socketThread.isChatOpened(chat,other_user_id)) {
                        
                        for (auto pair : *socketThread.connection_list) {
                            if (pair.first == other_user_id) {
                                if (!pair.second.send(msg.get_text())) {//  можу переробити щоб кидати не тльки  текст але не думаю що є сенс 
                                    std::cout << "err sending to " << other_user_id;
                                }
                                break;
                            }
                        }

             
                    }
                    else {
                        if (socketThread.current_user_id == socketThread.current_chat.getUser2Id()) {
                            socketThread.current_chat.setUnread1(socketThread.current_chat.getUnread1() + 1);
                            // socketThread.db->update_chat(socketThread.current_chat);

                        }
                        else {
                            socketThread.current_chat.setUnread2(socketThread.current_chat.getUnread2() + 1);
                        }
                        socketThread.db->update_chat(socketThread.current_chat);

                    }

                    // Обробка відправки повідомлення
                    break;

                case TypeRequest::ADD_NEW_CHAT:
                    // Обробка додавання нового чату
                    iResult = recv(socketThread.ClientSocket,
                        recvbuf,
                        recvbuflen,
                        0);
                    user_res = *(CUser*)recvbuf;
                    other_user_id = socketThread.db->get_user_id(user_res);
                    if (other_user_id == -1) {
                        other_user_id = 5;
                    }
                    chat.setUser1Id(socketThread.current_user_id);
                    chat.setUser2Id(other_user_id);
                    chat.setUser1(socketThread.db->get_user_by_id(socketThread.current_user_id));
                    chat.setUser2(socketThread.db->get_user_by_id(other_user_id));
                    socketThread.db->add_chat(chat);
                    std::memcpy(recvbuf, (char*)(&chat), sizeof(chat));
                    iSendResult = send(socketThread.ClientSocket, recvbuf, recvbuflen, 0);
                    if (iSendResult == SOCKET_ERROR) {
                        printf("send failed with error: %d\n", WSAGetLastError());
                        closesocket(socketThread.ClientSocket);
                        socketThread.isActive = false;
                        return;
                    }
                    // iSendResult
                    break;

                case TypeRequest::DELETE_CHAT:


                    break;

                case TypeRequest::FIND_PEOPLE:
                    memset(recvbuf, 0, recvbuflen);
                    iResult = recv(socketThread.ClientSocket,
                        recvbuf,
                        recvbuflen,
                        0);
                    users = socketThread.db->get_users();
                    user_res = *(CUser*)recvbuf;
                    memset(recvbuf, 0, recvbuflen);
                    for (auto us : users) {
                        if (strstr(us.getName(), user_res.getName())) {
                            memset(recvbuf, 0, recvbuflen);
                            std::memcpy(recvbuf, (char*)&us, sizeof(us));
                            iSendResult = send(socketThread.ClientSocket, recvbuf, sizeof(recvbuf), 0);
                            if (iSendResult == SOCKET_ERROR) {
                                printf("send failed with error: %d\n", WSAGetLastError());
                                closesocket(socketThread.ClientSocket);
                                socketThread.isActive = false;
                                return;
                            }
                        }
                    }
                    Sleep(1000);
                    iSendResult = send(socketThread.ClientSocket, std::to_string(TypeRequest::SECCESS).c_str(), sizeof(SECCESS), 0);
                    if (iSendResult == SOCKET_ERROR) {
                        printf("send failed with error: %d\n", WSAGetLastError());
                        closesocket(socketThread.ClientSocket);
                        socketThread.isActive = false;
                        return;
                    }
                    // Обробка пошуку людей
                    break;

                case TypeRequest::FINISH_WORK:
                //    it= std::find_if(socketThread.online->begin(), socketThread.online->end(),
                //        [socketThread](const auto& user) {
                //            return user.first == socketThread.current_user_id;
                //        });
                ////якщо є чат то кидати мб повідомлення про те що юзер вийшов ?
                //    // Перевірити, чи знайдено відповідний елемент
                //    if (it != socketThread.online->end()) {
                //        // Видалити елемент
                //        socketThread.online->erase(it);
                //        // Обробка завершення роботи
                        break;

                case TypeRequest::UPDATE_CHATS: // отримати  всі чати що повязані з поточним юзером 
                    // Обробка оновлення чатів
                    chats = socketThread.db->get_chats_with_user(socketThread.current_user_id);

                    for (auto ch : chats) {
                        memset(recvbuf, 0, recvbuflen);
                        std::memcpy(recvbuf, (char*)&ch, sizeof(ch));
                        iSendResult = send(socketThread.ClientSocket, recvbuf, sizeof(recvbuf), 0);
                        if (iSendResult == SOCKET_ERROR) {
                            printf("send failed with error: %d\n", WSAGetLastError());
                            closesocket(socketThread.ClientSocket);
                            socketThread.isActive = false;
                            return;
                        }
                    }
                    iSendResult = send(socketThread.ClientSocket, std::to_string(TypeRequest::SECCESS).c_str(), sizeof(SECCESS), 0);
                    if (iSendResult == SOCKET_ERROR) {
                        printf("send failed with error: %d\n", WSAGetLastError());
                        closesocket(socketThread.ClientSocket);
                        socketThread.isActive = false;
                        return;
                    }
                    break;
                case TypeRequest::GET_MESSAGES_FROM_CHAT:
                    // Обробка отримання повідомлень з чату
                    iResult = recv(socketThread.ClientSocket,
                        recvbuf,
                        recvbuflen,
                        0);
                    other_user_id = 0;
                    chat = *(CChat*)recvbuf;
                    msgs = socketThread.db->get_all_message_from_chat(chat);
                    for (auto msg : msgs) {
                        memset(recvbuf, 0, recvbuflen);
                        std::memcpy(recvbuf, (char*)&msg, sizeof(msg));
                        iSendResult = send(socketThread.ClientSocket, recvbuf, sizeof(recvbuf), 0);
                        if (iSendResult == SOCKET_ERROR) {
                            printf("send failed with error: %d\n", WSAGetLastError());
                            closesocket(socketThread.ClientSocket);
                            socketThread.isActive = false;
                            return;
                        }
                    }
                    Sleep(1000);
                    iSendResult = send(socketThread.ClientSocket, std::to_string(TypeRequest::SECCESS).c_str(), sizeof(SECCESS), 0);
                    if (iSendResult == SOCKET_ERROR) {
                        printf("send failed with error: %d\n", WSAGetLastError());
                        closesocket(socketThread.ClientSocket);
                        socketThread.isActive = false;
                        return;
                    }
                    break;

                case TypeRequest::OPEN_CHAT://те ж  що і пепереднє 

                    break;

                default:
                    // Обробка, якщо значення не відповідає жодному з case
                    break;
                 }
                
            }
            else if (iResult == 0)
                printf("Connection closing...\n");
            else {
                printf("recv failed with error: %d\n", WSAGetLastError());
                closesocket(socketThread.ClientSocket);
                socketThread.isActive = false;
                return;
            }

        } while (true);
    };
    void setThread(std::thread* th) {
        myThread = th;
    }
    
};

class SocketServer
{
    SOCKET ListenSocket = INVALID_SOCKET;
    std::vector<SockedThread> clients;
    CDatabase db;
    std::vector<int> online;
    std::vector<std::pair<int, MailSlotsSender>> connection_list;
    std::vector<std::thread*> threads;

public:
    SocketServer() {
        WSADATA wsaData;
        int iResult;
        struct addrinfo* result = NULL;
        struct addrinfo hints;

        // Initialize Winsock
        iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

        ZeroMemory(&hints, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;
        hints.ai_flags = AI_PASSIVE;

        // Resolve the server address and port
        iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
        if (iResult != 0) {
            throw std::exception();
        }

        // Create a SOCKET for the server to listen for client connections.
        ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
        if (ListenSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            freeaddrinfo(result);
            throw std::exception();
        }

        // Setup the TCP listening socket
        iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            printf("bind failed with error: %d\n", WSAGetLastError());
            freeaddrinfo(result);
            closesocket(ListenSocket);
            throw std::exception();
        }

        freeaddrinfo(result);
    }

    ~SocketServer() {
        closesocket(ListenSocket);
    }

    void Run() {
        while (true) {
            Listen();
            try {
                sockaddr* addr = NULL;
                SOCKET  cs = accept(ListenSocket, NULL, NULL);
                clients.emplace_back(SockedThread (cs,&db,&online,&connection_list, &clients));
                std::thread* th = new std::thread(SockedThread::Run, clients.back());
                threads.push_back(th);
                clients.back().setThread(th);
            }
            catch (std::exception e) {};
        }
    };

private:
    int Listen() {
        int iResult = listen(ListenSocket, SOMAXCONN);
        if (iResult == SOCKET_ERROR) {
            printf("listen failed with error: %d\n", WSAGetLastError());
            closesocket(ListenSocket);
            WSACleanup();
            throw std::exception();
        }
    }

};


