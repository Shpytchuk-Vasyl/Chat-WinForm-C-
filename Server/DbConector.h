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

    void update_chat(int id,CChat chat) const;
    std::vector<CMessage> get_all_message_from_chat(const CChat) const;

    int  get_user_id(const CUser)const;
    int get_chat_id(const CChat) const;
};

void CDatabase::add_user(const CUser user) const {
    if (!con->isValid()) {
        throw std::exception();
    }
    sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO users(name, password, avatar) VALUES (?, ?, ?)");
    pstmt->setString(1, user.s_name);
    pstmt->setString(2, user.s_password);
    pstmt->setInt(3, user.i_picture);
    pstmt->execute();
    delete pstmt;
}

int CDatabase::get_user_id(const CUser user)const {
    sql::PreparedStatement* pstmt = con->prepareStatement("SELECT id FROM users WHERE name = ?");
    pstmt->setString(1, user.s_name);

    sql::ResultSet* resultSet = pstmt->executeQuery();

    if (resultSet->next()) {
        int userId = resultSet->getInt("id");                                                                       //дописати оброблення додавання з однаковим імям
        delete resultSet;
        delete pstmt;
        return userId;
    }
    else {
        // Користувач з заданим іменем не знайдений
        delete resultSet;
        delete pstmt;
        return -1;
    }
}

int CDatabase::get_chat_id(const CChat chat)const {
    sql::PreparedStatement* pstmt = con->prepareStatement(
        "SELECT id FROM chats WHERE (first_user_id = ? AND second_user_id = ?) OR (first_user_id = ? AND second_user_id = ?)"
    );
    pstmt->setInt(1, chat.user1_id);
    pstmt->setInt(2, chat.user2_id);
    pstmt->setInt(3, chat.user2_id);
    pstmt->setInt(4, chat.user1_id);

    sql::ResultSet* resultSet = pstmt->executeQuery();

    if (resultSet->next()) {
        int chatId = resultSet->getInt("id");
        delete resultSet;
        delete pstmt;
        return chatId;
    }
    else {
        // Чат не знайдено
        delete resultSet;
        delete pstmt;
        return -1;
    }
}

void CDatabase::add_message(const CMessage msg) const {
    try {
        if (!con->isValid()) {
            throw std::exception();
        }
        // sql::Statement* stmt = con->createStatement();
        sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO messages(user_id, chat_id, content) VALUES (?, ?, ?)");
        pstmt->setInt(1, msg.user_id);
        pstmt->setInt(2, msg.chat_id);
        pstmt->setString(3, msg.text);
        pstmt->execute();
        delete pstmt;
    }
    catch (sql::SQLException& e) {
        std::cout << e.what();
    }
}

void CDatabase::add_chat(const CChat chat) const {
    if (!con->isValid()) {
        throw std::exception();
    }
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO chats(first_user_id, num_first_unread, second_user_id, num_second_unread) VALUES (?, ?, ?, ?)");
        pstmt->setInt(1, chat.user1_id);
        pstmt->setInt(2, chat.unread1);
        pstmt->setInt(3, chat.user2_id);
        pstmt->setInt(4, chat.unread2);

        pstmt->execute();
        delete pstmt;
    }
    catch (sql::SQLException& e) {
        std::cout << e.what();
    }
}

void CDatabase::update_chat(int id,CChat chat) const {
    sql::PreparedStatement* pstmt = con->prepareStatement(
        "UPDATE chats SET num_first_unread = ? WHERE id = ?"
    );
    pstmt->setInt(1, chat.unread1);
    pstmt->setInt(2, id);

    pstmt->executeUpdate();
    delete pstmt;
    sql::PreparedStatement* pstmt2 = con->prepareStatement(
        "UPDATE chats SET num_second_unread = ? WHERE id = ?"
    );
    pstmt2->setInt(1, chat.unread2);
    pstmt2->setInt(2, id);
    pstmt2->executeUpdate();
    delete pstmt2;
}

std::vector<CMessage> CDatabase::get_all_message_from_chat(const CChat chat) const {
    int chatId = get_chat_id(chat);
    sql::PreparedStatement* pstmt = con->prepareStatement(
        "SELECT * FROM messages WHERE chat_id = ?"
    );
    pstmt->setInt(1, chatId);
    sql::ResultSet* resultSet = pstmt->executeQuery();

    // Створення вектора для збереження результатів
    std::vector<CMessage> messages;
    while (resultSet->next()) {
        CMessage message;
        // Заповнення об'єкта CMessage даними з результату запиту
        message.user_id = resultSet->getInt("user_id");
        message.chat_id = resultSet->getInt("chat_id");
        std::memcpy(message.text ,std::string(resultSet->getString("content")).c_str(), 1024);
        std::memcpy(message.created_at, std::string(resultSet->getString("created_at")).c_str(), 20);

        // Додавання повідомлення до вектора
        messages.push_back(message);
    }

    // Звільнення ресурсів
    delete pstmt;
    delete resultSet;
    return messages;
}



