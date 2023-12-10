#pragma once
#include <windows.h> 
#include <iostream>
#include <stdio.h>
#include "MyForm.h"
#include <string>
#include <tchar.h>
#include <strsafe.h>
#include <algorithm>
#define SLOT_S L"\\\\.\\mailslot\\"
#define PIPE_TIMEOUT 5000
#define BUFSIZE 4096
//static std::wstring DESKTOP = L"\\\\DESKTOP-7CK1JB4\\mailslot\\";
//static std::wstring DESKTOP = L"\\\\LAPTOP-U2800VIR\\mailslot\\";

//
class MailSlotsReciver
{
    std::wstring userName;
    HANDLE hMailslot;


public:
    MailSlotsReciver(std::string  username) {
        userName = std::wstring(username.begin(), username.end());
        std::replace(userName.begin(), userName.end(), L' ', L'_');
        hMailslot = CreateMailslotW((SLOT_S + userName).c_str(), BUFSIZE, MAILSLOT_WAIT_FOREVER, nullptr);//xzzzzz W???
    }

    bool recive(std::string &msg) {
        char buffer[BUFSIZE];
        DWORD bytesRead = BUFSIZE;
       
        if (ReadFile(hMailslot, buffer,sizeof(buffer), &bytesRead, nullptr)) {
           
           // bytesRead = BUFSIZE;
           //ReadFile(hMailslot, buffer, bytesRead,nullptr, nullptr);
            std::cout << "Received message from client: " << bytesRead << std::endl;
           // buffer[bytesRead  +1 ] = '\0';
          //  ReadFile(hMailslot, buffer, sizeof(buffer) + 1, &bytesRead, nullptr);
            msg = std::string(buffer);
            return true;
        }
        else {
            std::cerr << "Failed to read from Mailslot. Error code: " << GetLastError() << std::endl;
            return false;
        }
    }

    ~MailSlotsReciver() {
        CloseHandle(hMailslot);
    }


};
