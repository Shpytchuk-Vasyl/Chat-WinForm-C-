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
#include "TypeRequest.h"
#include "../server/CUser.h"
#include "../server/CChat.h"
#include "../server/CMessage.h"
#include <vector>

class ServerConnection {
public:

    SOCKET ConnectSocket;
    char recvbuf[DEFAULT_BUFLEN] = { 0 };
    int recvbuflen = DEFAULT_BUFLEN;


public:
    ServerConnection()  {};

    bool Connect(std::string ip, std::string port) {
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
        iResult = getaddrinfo(DEFAULT_IP, DEFAULT_PORT, &hints, &result);
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

    int RegisterUser(CUser user) {
        send(ConnectSocket, std::to_string(TypeRequest::REGISTER_REQUEST).c_str(), sizeof(REGISTER_REQUEST), 0);

        int iResult = send(ConnectSocket, (char*)(&user), sizeof(user), 0);
        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
        }
        return iResult;
    }

    int addNewChat(CUser other) {
        send(ConnectSocket, std::to_string(TypeRequest::ADD_NEW_CHAT).c_str(), sizeof(ADD_NEW_CHAT), 0);

        int iResult = send(ConnectSocket, (char*)(&other), sizeof(other), 0);
        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
        }
        return iResult;
    }

    std::vector<CChat> getAllChats() {
        send(ConnectSocket, std::to_string(TypeRequest::START_REQUEST).c_str(), sizeof(START_REQUEST), 0);

        int size = 0;
        std::vector<CChat> chats;
        CChat chat;
        do {
            size = recv(ConnectSocket, (char*)&chat, sizeof(chat), 0);
            chats.push_back(chat);
        } while (size > 0);
        return chats;
    }

    int sendMessage(CMessage msg) {
        send(ConnectSocket, std::to_string(TypeRequest::SEND_MESSAGE).c_str(), sizeof(SEND_MESSAGE), 0);

        int iResult = send(ConnectSocket, (char*)(&msg), sizeof(msg), 0);
        if (iResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
        }
        return iResult;
    }

    int finishWork() {
        return send(ConnectSocket, std::to_string(TypeRequest::FINISH_WORK).c_str(), sizeof(FINISH_WORK), 0);
    }

    std::vector<CUser> getAllUsers(CUser name) {
        send(ConnectSocket, std::to_string(TypeRequest::FIND_PEOPLE).c_str(), sizeof(FIND_PEOPLE), 0);

        int size = 0;
        std::vector<CUser> users;
        CUser user;
        do {
            size = recv(ConnectSocket, (char*)&user, sizeof(user), 0);
            users.push_back(user);
        } while (size > 0);
        return users;
    }

    //Оновлює чати, що не є активними, тобто оновлює кількість не прочитаних повідомленнь
    std::vector<CChat> update() {
        send(ConnectSocket, std::to_string(TypeRequest::UPDATE_CHATS).c_str(), sizeof(UPDATE_CHATS), 0);

        int size = 0;
        std::vector<CChat> chats;
        CChat chat;
        do {
            size = recv(ConnectSocket, (char*)&chat, sizeof(chat), 0);
            chats.push_back(chat);
        } while (size > 0);
        return chats;
    }

    std::vector<CMessage> getAllMessageFromChat(CChat chat) {
        send(ConnectSocket, (char *)(&chat), sizeof(chat), 0);
        send(ConnectSocket, (std::to_string(0) + std::to_string(10)).c_str(), sizeof(chat), 0);

        int size = 0;
        std::vector<CMessage> msgs;
        CMessage msg;
        do {
            size = recv(ConnectSocket, (char*)&msg, sizeof(msg), 0);
            msgs.push_back(msg);
        } while (size > 0);
        return msgs;
    }


    //Pipe
    CMessage getMessageAsyn() {    
        return CMessage("Error :)", -1, -1);
    }

};
