#pragma once
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>


#include "CUser.h"
#include "CMessage.h"
#include "CChat.h"
#include <vector>
#include <string>
#include <memory>
#define USER "root"
#define PASSWORD "password"
#define PORT "tcp://127.0.0.1:3306"
#define DBNAME "data"
#define CONFIG "database_setup.sql"
//SOURCE C : / Users / Developer / Source / Repos / Shpytchuk - Vasyl / Chat - WinForm - C - / Server / database_setup.sql;
// команда для створення бази даних  перед цим треба ввійди в консоль mysql 
// C:\Program Files\MySQL\MySQL Server 8.2\bin>mysql -u root -p


class CDatabase {
public:
    sql::Connection* con;
    CDatabase() {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(PORT, USER, PASSWORD);
        con->setSchema(DBNAME);
    };
    void add_user(const CUser) const;
    void add_message(const CMessage) const;
    void add_chat(const CChat) const;

    void update_chat(CChat chat) const;
    std::vector<CMessage> get_all_message_from_chat(const CChat) const;

    int  get_user_id(const CUser)const;
    std::string get_message_text_by_id(int);
    std::vector<CChat> get_chats() const;
    
    std::vector<CChat> get_chats_with_user(int) const;
    CUser get_user_by_id(int) const;
    std::vector<CUser> get_users() const;
    int get_chat_id(const CChat) const;
};
