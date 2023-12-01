#include "SocketServe.h"
#include "PipeServer.h"



int __cdecl main(void)
{
   
    SocketServer s;
    std::thread t(&SocketServer::Run, s);
    PipeServer pipe;
    pipe.Run();
}