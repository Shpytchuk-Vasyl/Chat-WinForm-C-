#pragma once

class CChat
{
	int user1_id = 0;
	int user2_id = 0;
	int unread1 = 0;
	int unread2 = 0;
public: 
	friend class CDatabase;
	CChat(int u1, int u2):
		user1_id(u1),
		user2_id(u2)
	{}



};

