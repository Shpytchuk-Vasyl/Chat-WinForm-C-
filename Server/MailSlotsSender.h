#pragma once
#include <windows.h> 
#include <iostream>
#include <stdio.h>
#include <string>
#include <tchar.h>
#include <algorithm>
#include <strsafe.h>
#define SLOT_S L"\\\\.\\mailslot\\"
#define PIPE_TIMEOUT 5000
#define BUFSIZE 4096


	
class MailSlotsSender
{
	std::wstring userName;
	HANDLE hMailslot;


public:
    MailSlotsSender(std::string  username) {
        userName = std::wstring(username.begin(), username.end());
        std::replace(userName.begin(), userName.end(), L' ', L'_');
         

        hMailslot = CreateMailslotW((SLOT_S+userName).c_str(), 0, MAILSLOT_WAIT_FOREVER, nullptr);//xzzzzz W???

        if (hMailslot == INVALID_HANDLE_VALUE) {
            std::cout << "Failed to create Mailslot. Error code: " << GetLastError() << std::endl;
            throw std::exception();
        }
        std::cout << "Mailslot server is created" << std::endl;

    }

    bool send(std::string msg) {
        char buffer[BUFSIZE];
        DWORD bytesWritten;
        std::memcpy(buffer, msg.c_str(), sizeof(msg.c_str()));

        if (WriteFile(hMailslot, buffer, strlen(buffer) + 1, &bytesWritten, nullptr)) {
            std::cout << "Sended " << std::endl;
            return 1;
        }
        else {
            std::cerr << "Not sended: " << GetLastError() << std::endl;
            return 0;
        }

    }

    ~MailSlotsSender() {
        CloseHandle(hMailslot);
    }
    

};
		