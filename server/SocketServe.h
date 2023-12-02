#undef UNICODE

#define WIN32_LEAN_AND_MEAN
#include "../Client/TypeRequest.h"
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <vector>
#include <execution>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

class SockedThread {
    SOCKET ClientSocket = INVALID_SOCKET;
    std::thread* myThread;
    CDatabase* db;
    std::vector<int>* online;
    std::vector<std::pair<int, SOCKET>> *connectoin_list;
    CChat current_chat;
    int current_user_id = 0;
    bool isActive = true;
    int userId = 0;

public:
    SockedThread(SOCKET clientSocket) {
        this->ClientSocket = clientSocket;
        if (clientSocket == INVALID_SOCKET) throw std::exception();
                                                                                            // доініціалізувати поля ( поки немає звідки )
    }

    bool isOnline(int id) {
        auto it = std::find(online->begin(), online->end(), id);
        return it != online->end();
    }

    static void Run(SockedThread socketThread) {
        
       // socketThread.recvbuf[0] = 0;
        do {
            char recvbuf[DEFAULT_BUFLEN] = "";
            int recvbuflen = DEFAULT_BUFLEN;
            int iResult = 0;
          
            iResult = recv(socketThread.ClientSocket,
                    recvbuf,
                    recvbuflen,
                    0);

            if (iResult > 0) {
                //printf("Socked %d :Bytes received: %d\n", socketThread.ClientSocket, iResult);
                TypeRequest type= * reinterpret_cast<TypeRequest*>(recvbuf);
                 // отримання значення TypeRequest

                switch (type) {
                case TypeRequest::SECCESS://не може поідеї
                    // Обробка успішного виконання
                    break;

                case TypeRequest::REGISTER_REQUEST:
                    // Обробка запиту на реєстрацію
                    break;

                case TypeRequest::START_REQUEST://треба приймати імя та пароль ? 
                    // Обробка запиту на початок роботи
                    int iSendResult = send(socketThread.ClientSocket, std::to_string(TypeRequest::SECCESS).c_str(), sizeof(FIND_PEOPLE), 0);
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

                case TypeRequest::SEND_MESSAGE:
                    char msg[DEFAULT_BUFLEN] = "";
                    int size = DEFAULT_BUFLEN;
                    int iRes = 0;

                    iRes = recv(socketThread.ClientSocket,
                        msg,
                        size,
                        0);
                    int other_user_id = 0;
                    if (socketThread.current_user_id == socketThread.current_chat.getUser2Id()) {
                        other_user_id == socketThread.current_chat.getUser1Id();
                    }
                    else {
                        other_user_id == socketThread.current_chat.getUser2Id();
                    }
                    if (socketThread.isOnline(other_user_id)) {
                        SOCKET send_addr = INVALID_SOCKET;
                        for (auto pair : *socketThread.connectoin_list) {
                            if (pair.first == other_user_id) {
                                send_addr = pair.second;
                                break;
                            }
                        }
                        
                        if (send_addr != INVALID_SOCKET){
                            int iSendResult = send(send_addr, msg, size, 0);
                            if (iSendResult == SOCKET_ERROR) {
                                printf("send failed with error: %d\n", WSAGetLastError());
                                closesocket(socketThread.ClientSocket);
                                socketThread.isActive = false;
                                return;
                            }
                        }
                    }
                    else {
                        if (socketThread.current_user_id == socketThread.current_chat.getUser2Id()) {
                            socketThread.current_chat.setUnread1(socketThread.current_chat.getUnread1() + 1);
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
                    break;

                case TypeRequest::DELETE_CHAT:
                    // Обробка видалення чату
                    break;

                case TypeRequest::FIND_PEOPLE:
                    // Обробка пошуку людей
                    break;

                case TypeRequest::FINISH_WORK:
                    // Обробка завершення роботи
                    break;

                case TypeRequest::UPDATE_CHATS:
                    // Обробка оновлення чатів
                    break;

                case TypeRequest::GET_MESSAGES_FROM_CHAT:
                    // Обробка отримання повідомлень з чату
                    break;

                case TypeRequest::OPEN_CHAT:
                    // Обробка отримання повідомлень з чату
                    break;

                default:
                    // Обробка, якщо значення не відповідає жодному з case
                    break;
                }

                int iSendResult = send(socketThread.ClientSocket, recvbuf, iResult, 0);
                if (iSendResult == SOCKET_ERROR) {
                    printf("send failed with error: %d\n", WSAGetLastError());
                    closesocket(socketThread.ClientSocket);
                    socketThread.isActive = false;
                    return;
                }
                printf("Bytes sent: %d\n", iSendResult);
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
                clients.emplace_back(SockedThread (accept(ListenSocket, addr, NULL)));
                std::thread* th = new std::thread(SockedThread::Run, *clients.end());
                clients.end()->setThread(th);
            }
            catch (std::exception e) {};
        }
    };

private:
    int Listen() {
        while (listen(ListenSocket, SOMAXCONN));
        return 0;
    }

};


