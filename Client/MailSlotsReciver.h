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
    char buffer[BUFSIZE] = { 0 };

public:
    MailSlotsReciver(std::string  username) {
        userName = std::wstring(username.begin(), username.end());
        std::replace(userName.begin(), userName.end(), L' ', L'_');
        hMailslot = CreateMailslotW((SLOT_S + userName).c_str(), 0, MAILSLOT_WAIT_FOREVER, nullptr);//xzzzzz W???
    }

    bool recive(std::string& msg) {

        DWORD cbMessage, cMessage, cbRead;
        BOOL fResult;
        LPTSTR lpszBuffer;
        TCHAR achID[80];
        DWORD cAllMessages;
        HANDLE hEvent;
        OVERLAPPED ov;

        cbMessage = cMessage = cbRead = 0;

        hEvent = CreateEvent(NULL, FALSE, FALSE, userName.c_str());
        if (NULL == hEvent)
            return FALSE;
        ov.Offset = 0;
        ov.OffsetHigh = 0;
        ov.hEvent = hEvent;
       
        do {

        fResult = GetMailslotInfo(hMailslot, // mailslot handle 
            (LPDWORD)NULL,               // no maximum message size 
            &cbMessage,                   // size of next message 
            &cMessage,                    // number of messages 
            (LPDWORD)NULL);              // no read time-out 
        } while (cbMessage == MAILSLOT_NO_MESSAGE);
       

        cAllMessages = cMessage;

        // Allocate memory for the message. 

        lpszBuffer = (LPTSTR)GlobalAlloc(GPTR, cbMessage);
           
        lpszBuffer[0] = '\0';

        fResult = ReadFile(hMailslot,
            lpszBuffer,
            cbMessage,
            &cbRead,
            &ov);

        fResult = ReadFile(hMailslot,
            lpszBuffer,
            cbMessage,
            &cbRead,
            &ov);

        if (!fResult)
        {
            printf("ReadFile failed with %d.\n", GetLastError());
            GlobalFree((HGLOBAL)lpszBuffer);
            return FALSE;
        }

        _tprintf(TEXT("Contents of the mailslot: %s\n"), lpszBuffer);

        msg = std::string((char*)lpszBuffer);
        GlobalFree((HGLOBAL)lpszBuffer);   
        CloseHandle(hEvent);
        return TRUE;
  
        
        //DWORD bytesRead = 0;
        //      
        //   
        //if (ReadFile(hMailslot, &buffer, BUFSIZE, &bytesRead, nullptr)) {
        //    std::memset(buffer, 0, BUFSIZE);
        //    // bytesRead = BUFSIZE;
        //    //ReadFile(hMailslot, buffer, bytesRead,nullptr, nullptr);
        //    std::cout << "Received message from client: " << bytesRead << "Msg " << (char*)buffer << std::endl;
        //    // buffer[bytesRead  +1 ] = '\0';
        //    ReadFile(hMailslot, &buffer, bytesRead, &bytesRead, nullptr);
        //    msg = std::string(buffer);
        //    return true;

        //}
        //else {
        //    std::cerr << "Failed to read from Mailslot. Error code: " << GetLastError() << std::endl;
        //    return false;
        //}

    }

    ~MailSlotsReciver() {
        CloseHandle(hMailslot);
    }


};
