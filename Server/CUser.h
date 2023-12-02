#pragma once
#include <memory>
class CUser
{
private:
	char s_name[50] = "";
	char s_password[50] = "";
	int i_picture = 0;
public:
	friend class CDatabase;
	CUser(char name[50], char password[50],int picture) {
		std::memcpy(s_name, name, 50);
		std::memcpy(s_password, password, 50);
		i_picture = 0;
	}
	CUser(const char name[50],const  char password[50], int picture) {
		std::memcpy(s_name, name, 50);
		std::memcpy(s_password, password, 50);
		i_picture = 0;
	}
	
};

