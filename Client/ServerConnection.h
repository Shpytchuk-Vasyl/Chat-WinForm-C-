#pragma once
#include <string>
#include "TypeRequest.h"


 __interface ServerConnection
{
	 bool connect(std::string ip, std::string port);
	 int send(TypeRequest type, std::string info);
	 int receive(std::string& info);


};


 class SocketServer : ServerConnection{
	 bool connect(std::string ip, std::string port) {};
	 int send(TypeRequest type, std::string info) {};
	 int receive(std::string& info) {};

 };

 class PipeServer : ServerConnection {
	 bool connect(std::string ip, std::string port) {};
	 int send(TypeRequest type, std::string info) {};
	 int receive(std::string& info) {};

 };