#pragma once
#include <windows.h> 
#include <iostream>
#include <stdio.h>
#include "MyForm.h"
#include <string>
#include <tchar.h>
#include <strsafe.h>
#define SLOT_S L"\\\\.\\slot\\"
#define PIPE_TIMEOUT 5000
#define BUFSIZE 4096
static std::wstring DESKTOP = L"DESKTOP-7CK1JB4";
//static std::wstring DESKTOP = L"LAPTOP-U2800VIR";


class MailSlotsReciver
{
    std::wstring userName;
    HANDLE hMailslot;


public:
    MailSlotsReciver(std::string  username) {
        userName = std::wstring(username.begin(), username.end());
        HANDLE hMailslot = CreateFile((L"\\\\" + DESKTOP + L"\\slot\\" + userName).c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
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
