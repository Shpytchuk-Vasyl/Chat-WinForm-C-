#pragma once

#include "CUser.h"
#include "CMessage.h"
class CMessage
{

	
	char text[1024] = "";
	int user_id = 0;
	int chat_id = 0;
public:
	friend  class CDatabase;
	CMessage( const char msg[1024], int user, int chat):
		user_id(user),
		chat_id(chat)
	{std::memcpy(text, msg, 1024);}
	
};

