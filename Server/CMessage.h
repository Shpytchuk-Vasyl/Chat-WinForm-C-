#pragma once

#include <string>
#include "CUser.h"
class CMessage {	
	char text[1024] = "";
	int user_id = 0;
	int chat_id = 0;
	char created_at[20] = "";
    bool isMyMsg = false;

public:
	friend  class CDatabase;
	CMessage(){}
	CMessage( const char msg[1024], int user, int chat):
		user_id(user),
		chat_id(chat)
	{std::memcpy(text, msg, 1024);}
    CMessage(const CMessage& other) {
        // ������� �������� � ������ ��'���� �� ���������

        // ������� ����� ������
        std::memcpy(text, other.text,1024);

        // ������� ����� ������ ��������
        user_id = other.user_id;
        chat_id = other.chat_id;
        isMyMsg = other.isMyMsg;

        // ������� ����� ����
        std::memcpy(created_at, other.created_at,20);
    }


	std::string get_text() {
		std::string tex(text);
		return tex;
	}
	
    // ����� ��� user_id
    int get_user_id() const {
        return user_id;
    }

    // ����� ��� user_id
    void set_user_id(int user) {
        user_id = user;
    }

    int get_is_my_msg() const {
        return isMyMsg;
    }

    // ����� ��� user_id
    void set_is_my_msg(bool isMy) {
        isMyMsg = isMy;
    }

    // ����� ��� chat_id
    int get_chat_id() const {
        return chat_id;
    }

    // ����� ��� chat_id
    void set_chat_id(int chat) {
        chat_id = chat;
    }

    // ����� ��� created_at
    std::string get_created_at() const {
        return std::string(created_at);
    }

    // ����� ��� created_at
    void set_created_at(const char created[20]) {
        std::memcpy(created_at, created, 20);
    }
};

