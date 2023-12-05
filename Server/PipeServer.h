#pragma once
#include <windows.h> 
#include <stdio.h>
#include <string>
#include <tchar.h>
#include <strsafe.h>
#define PIPE_S L"\\\\.\\pipe\\"
#define PIPE_TIMEOUT 5000
#define BUFSIZE 4096

typedef struct _PIPEINST {
	OVERLAPPED oOverlap;
	HANDLE hPipeInst;
	TCHAR chRequest[BUFSIZE];
	DWORD cbRead;
	TCHAR chReply[BUFSIZE];
	DWORD cbToWrite;
} PIPEINST, * LPPIPEINST;

class PipeSender
{
	std::wstring pipe;
	std::wstring userName;
	HANDLE hPipe;
	//LPPIPEINST lpPipeInst;

public:
	PipeSender(const std::string& user) {
		userName = std::wstring(user.begin(), user.end());
		pipe = PIPE_S + userName;


		HANDLE hConnectEvent;

		DWORD dwWait, cbRet;
		bool fSuccess, fPendingIO;
		hConnectEvent = CreateEvent(
			NULL,    // default security attribute
			TRUE,    // manual reset event 
			TRUE,    // initial state = signaled 
			NULL);   // unnamed event object 

		if (hConnectEvent == NULL)
		{
			printf("CreateEvent failed with %d.\n", GetLastError());
		}
		std::wstring nonConstPipe = pipe;

		// Get the non-const pointer
		LPTSTR lpszPipename = (LPTSTR)pipe.c_str();
		hPipe = CreateNamedPipe(
			lpszPipename,             // pipe name 
			PIPE_ACCESS_DUPLEX |      // read/write access 
			FILE_FLAG_OVERLAPPED,     // overlapped mode 
			PIPE_TYPE_MESSAGE |       // message-type pipe 
			PIPE_READMODE_MESSAGE |   // message read mode 
			PIPE_WAIT,                // blocking mode 
			PIPE_UNLIMITED_INSTANCES, // unlimited instances 
			BUFSIZE * sizeof(TCHAR),    // output buffer size 
			BUFSIZE * sizeof(TCHAR),    // input buffer size 
			PIPE_TIMEOUT,             // client time-out 
			NULL);                    // default security attributes
		if (hPipe == INVALID_HANDLE_VALUE)
		{
			printf("CreateNamedPipe failed with %d.\n", GetLastError());
			throw std::exception("err conect pipe");
		}
		Conect();
			if (!fSuccess)
			{
				printf("ConnectNamedPipe (%d)\n", GetLastError());
				throw std::exception();
			}
			LPPIPEINST lpPipeInst = (LPPIPEINST)GlobalAlloc(
				GPTR, sizeof(PIPEINST));
			if (lpPipeInst == NULL)
			{
				printf("GlobalAlloc failed (%d)\n", GetLastError());
				throw std::exception();
			}	
	};
	bool Conect() {
		BOOL fConnected, fPendingIO = FALSE;
		fConnected = ConnectNamedPipe(hPipe, NULL);
		if (fConnected) {
			return 0;
		}
		switch (GetLastError())
		{
			case ERROR_IO_PENDING:
				fPendingIO = TRUE;
				break;
			case ERROR_PIPE_CONNECTED:
					break;
			default:
			{
				printf("ConnectNamedPipe failed with %d.\n", GetLastError());
				throw std::exception("err conect pipe");
			}
		}
		return fPendingIO;
	}

	void send(std::string msg) {
		DWORD cbWritten = 0;  // Змінна для зберігання кількості записаних байтів
		bool fSuccess = WriteFile(
			hPipe,                // handle на канал
			msg.c_str(),          // повідомлення
			static_cast<DWORD>(msg.size()),  // розмір повідомлення
			&cbWritten,           // кількість записаних байтів
			NULL);
	}

};

