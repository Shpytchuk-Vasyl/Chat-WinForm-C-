#pragma once
#include "ServerConnection.h"
#include "TypeRequest.h"
#include "../server/CUser.h"

class RequestManager
{
	ServerConnection* server;
	TypeRequest typeRequest;
	std::string info;

public:
	RequestManager(ServerConnection *sv, std::string in) {
		server = sv;
		info = in;
	}


	static const char* generateMessage(TypeRequest typeRequest, std::string info) {
		return (std::to_string(typeRequest) + "\n" + info).c_str();
	}


	void updateChats() {

	}

	static CUser RegisterUser(std::string name, std::string password, int iconIndex) {
		return CUser(name.c_str(), password.c_str(), iconIndex);
	}

	static std::string GetMessage() {
		return "";
	}

	static std::string SendMessage(std::string chatName, std::string message) {
		return "CHAT : " + chatName + "\n" +
			"MESSAGE : " + message;
	}

	static std::string AddNewChat(std::string chatName, short participant_id) {
		return  "CHAT : " + chatName + "\n" +
			"USERID : " + std::to_string(participant_id);
	}
};

