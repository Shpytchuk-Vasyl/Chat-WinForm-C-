#pragma once
#include "CUser.h"
class CChat
{
    int user1_id = 0;
    int user2_id = 0;
    int unread1 = 0;
    int unread2 = 0;
    int chat_id = 0;
    CUser user1, user2;
public:
    bool operator ==(CChat ch) {
        if ((user1_id == ch.user1_id || user1_id == ch.user2_id) && (user2_id == ch.user1_id || user2_id == ch.user2_id)) {
            return true;
        }
        return false;
    }
    friend class CDatabase;
    CChat(int u1, int u2) :
        user1_id(u1),
        user2_id(u2)
    {}
    CChat(int chat_id) :
        chat_id(chat_id)
    {}
    CChat() {}

    CChat(const CChat& other) {
        // Копіюємо значення з іншого об'єкта до поточного
        user1_id = other.user1_id;
        user2_id = other.user2_id;
        unread1 = other.unread1;
        unread2 = other.unread2;
        chat_id = other.chat_id;

        // Викликаємо конструктор копіювання для об'єктів класу CUser
        user1 = other.user1;
        user2 = other.user2;
    }

    // Getter for user2_id
    int getUser1Id()  {
        return user1_id;
    }

    // Setter for user2_id
    void setUser1Id(int id) {
        user1_id = id;
    }


    // Getter for user2_id
    int getUser2Id() {
        return user2_id;
    }

    // Setter for user2_id
    void setUser2Id(int id) {
        user2_id = id;
    }



    // Getter for unread1
    int getUnread1()  {
        return unread1;
    }

    // Setter for unread1
    void setUnread1(int unread) {
        unread1 = unread;
    }

    // Getter for unread2
    int getUnread2() {
        return unread2;
    }
    void setChatId(int id) {
        chat_id = id;
    }

    int getChatId() {
        return chat_id;
    }

    // Setter for unread2
    void setUnread2(int unread) {
        unread2 = unread;
    }

    CUser getUser2()  {
        return user2;
    }

    void setUser2(CUser us) {
        user2 = us;
    }

    CUser getUser1()  {
        return user1;
    }

    void setUser1(CUser us) {
        user1 = us;
    }



};
