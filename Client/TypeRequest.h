#pragma once
static const size_t DEFAULT_BUFLEN = 8192;
static const char* DEFAULT_PORT = "31098";
static const char* DEFAULT_IP = "localhost";

enum TypeRequest {
	SECCESS,
	ERR,// опечатка , не хочу змінювати всюди , тому просто буду так юзав поки , потім побацим 
	REGISTER_REQUEST,
	START_REQUEST,
	GET_MESSAGE,
	SEND_MESSAGE,
	ADD_NEW_CHAT,
	DELETE_CHAT,
	FIND_PEOPLE,
	FINISH_WORK,
	UPDATE_CHATS,
	GET_MESSAGES_FROM_CHAT,
	OPEN_CHAT
};