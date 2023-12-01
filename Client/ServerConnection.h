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


class ServerConnection {
public:
	 virtual bool Connect(std::string ip, std::string port) = 0;
	 virtual int Send(TypeRequest type, std::string info) = 0;
	 virtual int Receive(std::string& info) = 0;


};


 class SocketServer : ServerConnection{
     SOCKET ConnectSocket = INVALID_SOCKET;
     char recvbuf[DEFAULT_BUFLEN] = {0};
     int recvbuflen = DEFAULT_BUFLEN;


 public:
     SocketServer() {
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
     }
	 bool Connect(std::string ip, std::string port) {
         return true;
	 };

     int Send(TypeRequest type, std::string info) {
         int iResult = send(ConnectSocket, info.c_str(), info.size(), 0);
         if (iResult == SOCKET_ERROR) {
             printf("send failed with error: %d\n", WSAGetLastError());
         }
         return iResult;
     };
	 
     int Receive(std::string& info) {
         int iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
         if (iResult > 0)
             printf("Bytes received: %d\n", iResult);
         else if (iResult == 0)
             printf("Connection closed\n");
         else
             printf("recv failed with error: %d\n", WSAGetLastError());

         info = recvbuf;
         return iResult;
     };

 };

 class PipeServer : ServerConnection {
 public:

	 bool Connect(std::string ip, std::string port) {};
	 int Send(TypeRequest type, std::string info) {};
	 int Receive(std::string& info) {};

 };



