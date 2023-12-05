#pragma once
#include <memory>
class CUser
{
private:
	char s_name[50] = "";
	char s_password[50] = "";
	int i_picture = 0;
    bool is_online = false;
public:
    friend class CPipeReciver;
	friend class CDatabase;
    CUser() {};
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
	

    // Getter for s_name
    char* getName() {
        return s_name;
    }

    // Setter for s_name
    void setName(char name[50]) {
        std::memcpy(s_name, name, 50);
    }

    // Getter for s_password
    const char* getPassword() const {
        return s_password;
    }

    // Setter for s_password
    void setPassword(char password[50]) {
        std::memcpy(s_password, password, 50);
    }

    // Getter for i_picture
    int getPicture() const {
        return i_picture;
    }

    // Setter for i_picture
    void setPicture(int picture) {
        i_picture = picture;
    }

    bool getStatus() {
        return is_online;
    }
};


