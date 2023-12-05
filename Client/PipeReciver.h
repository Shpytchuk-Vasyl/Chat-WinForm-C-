#pragma once
#include <windows.h> 
#include <stdio.h>
#include <string>
#include <tchar.h>
#include <strsafe.h>
#include "../Server/CUser.h"

#include "ChatNode.h"
#include <msclr\marshal_cppstd.h>

#define PIPE_TIMEOUT 5000
#define BUFSIZE 4096
#define PIPE_S L"\\\\.\\pipe\\" // визначено в сервері , треба буде в спільний винести 
class CPipeReciver {
	std::wstring pipe;
	CUser User;
	LPTSTR lpszPipename;
	HANDLE hPipe;

	CPipeReciver( CUser user) {
		User = user;
		std::wstring userName = std::wstring(std::string(User.getName()).begin(), std::string(User.getName()).end());
		pipe = PIPE_S + userName; //щось з юзером , не всі функції є 


		//HANDLE hConnectEvent;

		DWORD dwWait, cbRet;
		bool fSuccess, fPendingIO;
		//hConnectEvent = CreateEvent(
		//	NULL,    // default security attribute
		//	TRUE,    // manual reset event 
		//	TRUE,    // initial state = signaled 
		//	NULL);   // unnamed event object 

		/*if (hConnectEvent == NULL)
		{
			printf("CreateEvent failed with %d.\n", GetLastError());
		}*/
		//std::wstring nonConstPipe = pipe;

		// Get the non-const pointer
		lpszPipename = (LPTSTR)pipe.c_str();
		           // default security attributes
		hPipe = CreateFile(
			lpszPipename,   // pipe name 
			GENERIC_READ |  // read and write access 
			GENERIC_WRITE,
			0,              // no sharing 
			NULL,           // default security attributes
			OPEN_EXISTING,  // opens existing pipe 
			0,              // default attributes 
			NULL);


		if (GetLastError() != ERROR_PIPE_BUSY)
		{
			throw std::exception();
			
		}

	};
	bool Conect() {
		
		if (!WaitNamedPipe(lpszPipename, 20000))
		{
			printf("Could not open pipe: 20 second wait timed out.");
			return 0;
		}
		else {
			return 1;
		}
	}
	std::string read() {
		char buffer[BUFSIZE];
		DWORD bytesRead;
		if (ReadFile(hPipe, &buffer, sizeof(buffer) - 2, &bytesRead, NULL) != FALSE) {
			std::string str(buffer);
			return str;
		}
		else {
			throw std::exception();
		}

	
	}

	static void ThreadRead(CPipeReciver reciver, Guna::UI2::WinForms::Guna2Panel^ PlaceForMessages) {
		while (true) {
			std::string res =reciver.read();
			Client::MessageNode(msclr::interop::marshal_as<System::String^>(res), false, 1);// треба щоб сетав картинку сам по інфі про юзера з чату 
			//PlaceForMessages->Controls->Add();// не той клас створив , треба 
			
		}
	}
};