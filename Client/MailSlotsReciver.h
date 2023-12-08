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



class MailSlotsReciver
{
    std::wstring userName;
    HANDLE hMailslot;


public:
    MailSlotsReciver(std::string  username) {
        userName = std::wstring(username.begin(), username.end());
        std::replace(userName.begin(), userName.end(), L' ', L'_');
        HANDLE hMailslot = CreateFileW((L"\\\\DESKTOP-7CK1JB4\\mailslot\\"+userName).c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
        if (hMailslot == INVALID_HANDLE_VALUE) {
           
            throw std::exception();
        }
    }

    bool recive(std::string &msg) {
        char buffer[BUFSIZE];
        DWORD bytesRead;
       
        if (ReadFile(hMailslot, buffer, sizeof(buffer), &bytesRead, nullptr)) {
            std::cout << "Received message from client: " << std::endl;
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
