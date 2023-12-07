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
        // Копіюємо значення з іншого об'єкта до поточного

        // Копіюємо рядок тексту
        std::memcpy(text, other.text,1024);

        // Копіюємо прості числові значення
        user_id = other.user_id;
        chat_id = other.chat_id;
        isMyMsg = other.isMyMsg;

        // Копіюємо рядок дати
        std::memcpy(created_at, other.created_at,20);
    }


	std::string get_text() {
		std::string tex(text);
		return tex;
	}
	
    // Гетер для user_id
    int get_user_id() const {
        return user_id;
    }

    // Сетер для user_id
    void set_user_id(int user) {
        user_id = user;
    }

    int get_is_my_msg() const {
        return isMyMsg;
    }

    // Сетер для user_id
    void set_is_my_msg(bool isMy) {
        isMyMsg = isMy;
    }

    // Гетер для chat_id
    int get_chat_id() const {
        return chat_id;
    }

    // Сетер для chat_id
    void set_chat_id(int chat) {
        chat_id = chat;
    }

    // Гетер для created_at
    std::string get_created_at() const {
        return std::string(created_at);
    }

    // Сетер для created_at
    void set_created_at(const char created[20]) {
        std::memcpy(created_at, created, 20);
    }
};

