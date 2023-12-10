#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#include <string>
#include <mutex>
#include "TypeRequest.h"
#include "../server/CUser.h"
#include "../server/CChat.h"
#include "../server/CMessage.h"
#include <vector>


class ServerConnection {
    std::mutex serverMutex;
public:
    
    SOCKET ConnectSocket;
    char recvbuf[DEFAULT_BUFLEN] = { 0 };
    int recvbuflen = DEFAULT_BUFLEN;

public:
    ServerConnection()  {};

    bool Connect(const char* ip, const char* port) {
        WSADATA wsaData;
        struct addrinfo* result = NULL,
            * ptr = NULL,
            hints;
        const char* sendbuf = "this is a test";

        // Initialize Winsock
        int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (iResult != 0) {
            printf("WSAStartup failed with error: %d\n", iResult);
            throw std::exception();
        }

        ZeroMemory(&hints, sizeof(hints));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;

        // Resolve the server address and port
        iResult = getaddrinfo(ip, port, &hints, &result);
        if (iResult != 0) {
            printf("getaddrinfo failed with error: %d\n", iResult);
            throw std::exception();
        }

        // Attempt to connect to an address until one succeeds
        for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

            // Create a SOCKET for connecting to server
            ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
                ptr->ai_protocol);
            if (ConnectSocket == INVALID_SOCKET) {
                printf("socket failed with error: %ld\n", WSAGetLastError());
                throw std::exception();
            }

            // Connect to server.
            iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
            if (iResult == SOCKET_ERROR) {
                closesocket(ConnectSocket);
                ConnectSocket = INVALID_SOCKET;
                continue;
            }
            break;
        }

        freeaddrinfo(result);

        if (ConnectSocket == INVALID_SOCKET) {
            printf("Unable to connect to server!\n");
            throw std::exception();
        }
        return true;
    };

    bool RegisterUser(CUser user) {
        send(ConnectSocket, std::to_string(TypeRequest::REGISTER_REQUEST).c_str(), sizeof(TypeRequest), 0);

        int iResult = send(ConnectSocket, (char*)(&user), sizeof(user), 0);
        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
        }

        char buf[10];
        iResult = recv(ConnectSocket, buf, sizeof(buf), 0);
        TypeRequest type = (TypeRequest)std::atoi(buf);
        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
        }
         
        return type == SECCESS;
    }

    bool createSlot() {
        send(ConnectSocket, std::to_string(TypeRequest::SLOT_CREATED).c_str(), sizeof(TypeRequest), 0);
        WCHAR computerNameWCHAR[100] = { 0 };
        DWORD size = 100;
        GetComputerName(computerNameWCHAR, &size);
        char computerName[DEFAULT_BUFLEN] = "";
        for (size_t i = 0; i <= size; i++)
            computerName[i] = computerNameWCHAR[i];
        return SOCKET_ERROR != send(ConnectSocket, (char*)computerName, DEFAULT_BUFLEN, 0);

    }

    CChat addNewChat(CUser other) {
        serverMutex.lock();
        int iResult = send(ConnectSocket, std::to_string(TypeRequest::ADD_NEW_CHAT).c_str(), sizeof(ADD_NEW_CHAT), 0);
        iResult = send(ConnectSocket, (char*)(&other), sizeof(other), 0);
        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
        }
        CChat chat;
        char recvbuf[DEFAULT_BUFLEN] = "";
        iResult = recv(ConnectSocket, recvbuf, DEFAULT_BUFLEN, 0);
        std::memcpy((char*)&chat, recvbuf, sizeof(chat));
        memset(recvbuf, 0, DEFAULT_BUFLEN);
        serverMutex.unlock();
        return  chat;
    }

    bool Start(CUser user) {
        send(ConnectSocket, std::to_string(TypeRequest::START_REQUEST).c_str(), sizeof(TypeRequest), 0);
        Sleep(100);
        return SOCKET_ERROR != send(ConnectSocket, (char*)(&user), sizeof(user), 0);
        
    }

    bool sendMessage(CMessage msg) {
        serverMutex.lock();
        send(ConnectSocket, std::to_string(TypeRequest::SEND_MESSAGE).c_str(), sizeof(TypeRequest), 0);
        Sleep(100);
        int iResult = send(ConnectSocket, (char*)(&msg), sizeof(msg), 0);     
        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
        }
        serverMutex.unlock();
        return iResult != SOCKET_ERROR;
    }

    bool finishWork() {
        return SOCKET_ERROR != send(ConnectSocket, std::to_string(TypeRequest::FINISH_WORK).c_str(), sizeof(TypeRequest), 0);
    }

    std::vector<CUser> getAllUsers(CUser name) {
        serverMutex.lock();
        send(ConnectSocket, std::to_string(TypeRequest::FIND_PEOPLE).c_str(), sizeof(TypeRequest), 0);
        Sleep(100);
        send(ConnectSocket, (char*)&name, sizeof(name), 0);
        char recvbuf[DEFAULT_BUFLEN] = "";
        int iResult = 0;
        std::vector<CUser> users;
        CUser user;
        do {
            iResult = recv(ConnectSocket, recvbuf, DEFAULT_BUFLEN, 0);
            std::memcpy((char*)&user, recvbuf, sizeof(user));
            memset(recvbuf, 0, DEFAULT_BUFLEN);

            if (iResult == SOCKET_ERROR) {
                throw std::exception();
            }
            else if (iResult <= sizeof(TypeRequest)) break;
            users.push_back(user);
            user = CUser();
        } while (true);
        serverMutex.unlock();
        return users;
    }

    //Оновлює чати, що не є активними, тобто оновлює кількість не прочитаних повідомленнь
    std::vector<CChat> update() {
        serverMutex.lock();
        send(ConnectSocket, std::to_string(TypeRequest::UPDATE_CHATS).c_str(), sizeof(TypeRequest), 0);
        char recvbuf[DEFAULT_BUFLEN] = "";
        int iResult = 0;
        std::vector<CChat> chats;
        CChat chat;
        do {
            iResult = recv(ConnectSocket, recvbuf, DEFAULT_BUFLEN, 0);
            std::memcpy((char*)&chat, recvbuf, sizeof(chat));
            memset(recvbuf, 0, DEFAULT_BUFLEN);

            if (iResult == SOCKET_ERROR) {
                throw std::exception();
            }
            else if (iResult <= sizeof(TypeRequest)) break;
            chats.push_back(chat);
        } while (true);
        serverMutex.unlock();
        return chats;
    }

    std::vector<CMessage> getAllMessageFromChat(CChat chat) {
        serverMutex.lock();
        send(ConnectSocket, std::to_string(TypeRequest::GET_MESSAGES_FROM_CHAT).c_str(), sizeof(TypeRequest), 0);
        Sleep(100);
        send(ConnectSocket, (char *)(&chat), sizeof(chat), 0);
        char recvbuf[DEFAULT_BUFLEN] = "";

        int iResult = 0;
        std::vector<CMessage> msgs;
        CMessage msg;
        do {
            iResult = recv(ConnectSocket, recvbuf, DEFAULT_BUFLEN, 0);
            std::memcpy((char*)&msg, recvbuf, sizeof(msg));
            memset(recvbuf, 0, DEFAULT_BUFLEN);
            if (iResult == SOCKET_ERROR) {
                throw std::exception();
            }
            else if (iResult <= sizeof(TypeRequest)) break;
            msgs.push_back(msg);
        } while (true);
        serverMutex.unlock();
        return msgs;
    }


};
