#pragma once
#include <thread>
#include "PipeServer.h"
#include "SocketServer.h"

class Server
{
public:
	void Run() {
		PipeServer pipe;
		std::thread t(PipeServer::Run, pipe);
		SocketServer socket;
		socket.Run();
	};
private:



};

