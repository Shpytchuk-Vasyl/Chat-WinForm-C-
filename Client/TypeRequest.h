#pragma once
static const size_t DEFAULT_BUFLEN = 8192;
static const char* DEFAULT_PORT = "31098";
static const char* DEFAULT_IP = "localhost";

enum TypeRequest {
	SECCESS,
	REGISTER_REQUEST,
	START_REQUEST,
	GET_MESSAGES,
	SEND_MESSAGE,
	ADD_NEW_CHAT,
	DELETE_CHAT,
	FIND_PEOPLE,
	FINISH_WORK,
};