#pragma once
#include "ServerConnection.h"
#include "TypeRequest.h"
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

	static std::string RegisterUser(std::string name, std::string surName, std::string phone, std::string email) {
		return "FIRST_NAME : " + name + "\n" +
			"LAST_NAME : " + surName + "\n" +
			"PHONE : " + phone + "\n" +
			"EMAIL : " + email + "\n";
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

