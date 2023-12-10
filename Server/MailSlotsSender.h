#pragma once
#include <windows.h> 
#include <iostream>
#include <stdio.h>
#include <string>
#include <tchar.h>
#include <algorithm>
#include <strsafe.h>
#define SLOT_S L"\\\\"
#define SLOT_S2 L ""
#define PIPE_TIMEOUT 5000
#define BUFSIZE 4096

//
	
class MailSlotsSender
{
	std::wstring userName;
	HANDLE hMailslot = INVALID_HANDLE_VALUE;
    std::wstring hostName;


public:
    MailSlotsSender(std::string  username, std::string hostname) {
        userName = std::wstring(username.begin(), username.end());
        hostName = std::wstring(hostname.begin(), hostname.end());
        std::replace(userName.begin(), userName.end(), L' ', L'_');
        int c = 0;
       // CreateFile(L"\\\\.\\mailslot\\MyMailslot", GENERIC_WRITE, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
        hMailslot = CreateFileW((SLOT_S + hostName + L"\\mailslot\\" + userName).c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
    

        std::cout << " hcreated =" << hMailslot << std::endl;
      /*  if (hMailslot == INVALID_HANDLE_VALUE) {
            std::cout << "Failed to create Mailslot. Error code: " << GetLastError() << std::endl;
            throw std::exception();
        }*/
        std::cout << "Mailslot server is created" << std::endl;

    }

    bool send(std::string msg) {
        char buffer[BUFSIZE] = " ";
        DWORD bytesWritten = BUFSIZE;
        std::memcpy(buffer, msg.c_str(), sizeof(msg.c_str()));
        std::cout << " h =" << hMailslot << " msg = " << msg << std::endl;

        if (WriteFile(hMailslot, buffer,msg.size(), &bytesWritten, nullptr)) {
            std::cout << "Sended " << msg<< " size:" << bytesWritten << " "<< msg.size() << std::endl;
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
		