#pragma once
#include <string>
#include "TypeRequest.h"


class ServerConnection {
public:
	 virtual bool connect(std::string ip, std::string port) = 0;
	 virtual int send(TypeRequest type, std::string info) = 0;
	 virtual int receive(std::string& info) = 0;


};


 class SocketServer : ServerConnection{
 public:
	 bool connect(std::string ip, std::string port) {};
	 int send(TypeRequest type, std::string info) {};
	 int receive(std::string& info) {};

 };

 class PipeServer : ServerConnection {
 public:

	 bool connect(std::string ip, std::string port) {};
	 int send(TypeRequest type, std::string info) {};
	 int receive(std::string& info) {};

 };