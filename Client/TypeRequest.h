#pragma once
static const size_t DEFAULT_BUFLEN = 4096;
static const char* DEFAULT_PORT = "31098";

enum TypeRequest {
	GET_CHATS = 0,
	GET_MESSAGES,
	SEND_MESSAGE,
	GET_NEW_MESSAGES,
};