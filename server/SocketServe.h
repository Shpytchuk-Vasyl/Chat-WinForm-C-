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
    bool isActive = true;
    int userId = 0;

public:
    SockedThread(SOCKET clientSocket) {
        this->ClientSocket = clientSocket;
        if (clientSocket == INVALID_SOCKET) throw std::exception();
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
                printf("Socked %d :Bytes received: %d\n", socketThread.ClientSocket, iResult);

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


