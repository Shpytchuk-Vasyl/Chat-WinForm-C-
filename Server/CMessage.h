#pragma once

#include <string>
#include "CUser.h"
#include "CMessage.h"
class CMessage {	
	char text[1024] = "";
	int user_id = 0;
	int chat_id = 0;
	char created_at[20] = "";

public:
	friend  class CDatabase;
	CMessage(){}
	CMessage( const char msg[1024], int user, int chat):
		user_id(user),
		chat_id(chat)
	{std::memcpy(text, msg, 1024);}
	
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

