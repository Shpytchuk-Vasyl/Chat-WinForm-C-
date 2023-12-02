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
	
};

