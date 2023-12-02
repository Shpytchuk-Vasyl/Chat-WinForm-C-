#pragma once
#include "CUser.h"
class CChat
{
    int user1_id = 0;
    int user2_id = 0;
    int unread1 = 0;
    int unread2 = 0;
    CUser user1, user2;
public:
    friend class CDatabase;
    CChat(int u1, int u2) :
        user1_id(u1),
        user2_id(u2)
    {}
    CChat() {}
    // Getter for user1_id
    int getUser1Id() const {
        return user1_id;
    }

    // Setter for user1_id
    void setUser1Id(int id) {
        user1_id = id;
    }

    // Getter for user2_id
    int getUser2Id() const {
        return user2_id;
    }

    // Setter for user2_id
    void setUser2Id(int id) {
        user2_id = id;
    }

    // Getter for user2_id
    int getUser2Id() const {
        return user2_id;
    }

    // Setter for user2_id
    void setUser2Id(int id) {
        user2_id = id;
    }

    // Getter for unread1
    int getUnread1() const {
        return unread1;
    }

    // Setter for unread1
    void setUnread1(int unread) {
        unread1 = unread;
    }

    // Getter for unread2
    int getUnread2() const {
        return unread2;
    }

    // Setter for unread2
    void setUnread2(int unread) {
        unread2 = unread;
    }

    CUser getUser2() const {
        return user2;
    }

    void setUser2(CUser us) {
        user2 = us;
    }

    CUser getUser1() const {
        return user1;
    }

    void setUser1(CUser us) {
        user1 = us;
    }
};
