#pragma once
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <exception>
#include "../Client/TypeRequest.h"

class SocketServer
{
    SOCKET ListenSocket = INVALID_SOCKET;

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
                SockedThread client(accept(ListenSocket, addr, NULL));
                std::thread thread(SockedThread::Run, client);
            }
            catch (std::exception e) {};
        }
    };

private:
    int Listen() {
        while(listen(ListenSocket, SOMAXCONN));
        return 0;
    }

};

class SockedThread {
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    SOCKET ClientSocket = INVALID_SOCKET;

public:
    SockedThread(SOCKET clientSocket) {
        this->ClientSocket = clientSocket;
        if (clientSocket == INVALID_SOCKET) throw std::exception();
    }

    static void Run(SockedThread socketThread) {
        int iResult = 0;
        do {
            iResult = recv(socketThread.ClientSocket,
                socketThread.recvbuf,
                socketThread.recvbuflen,
                0);

            if (iResult > 0) {
                printf("Socked %d :Bytes received: %d\n", socketThread.ClientSocket, iResult);

                int iSendResult = send(socketThread.ClientSocket, socketThread.recvbuf, iResult, 0);
                if (iSendResult == SOCKET_ERROR) {
                    closesocket(socketThread.ClientSocket);
                    return;
                }
                printf("Bytes sent: %d\n", iSendResult);
            }
            else if (iResult == 0)
                printf("Connection closing...\n");
            else {
                printf("recv failed with error: %d\n", WSAGetLastError());
                closesocket(socketThread.ClientSocket);
                return;
            }

        } while (true);
    };

};
