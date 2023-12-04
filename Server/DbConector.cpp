#include "DbConector.h"

std::vector<CChat> CDatabase::get_chats_with_user(int user_id) const {
    std::vector<CChat> result;
    sql::PreparedStatement* pstmt = con->prepareStatement(
        "SELECT * FROM chats WHERE first_user_id = ? OR second_user_id = ?"
    );
    pstmt->setInt(1, user_id);
    pstmt->setInt(2, user_id);

    sql::ResultSet* resultSet = pstmt->executeQuery();

    while (resultSet->next()) {

        CChat chat;
        chat.setUser1Id(resultSet->getInt("first_user_id"));
        chat.setUnread1(resultSet->getInt("num_first_unread"));
        chat.setUser2Id(resultSet->getInt("second_user_id"));
        chat.setUnread2(resultSet->getInt("num_second_unread"));
        chat.setChatId(resultSet->getInt("id"));

        // Отримати дані користувачів, які учасники чату
        chat.setUser1(get_user_by_id(chat.getUser1Id()));
        chat.setUser2(get_user_by_id(chat.getUser2Id()));

        result.push_back(chat);
        result.push_back(chat);
    }

    delete resultSet;
    delete pstmt;
    return result;
}

std::string CDatabase::get_message_text_by_id(int message_id) {
    sql::PreparedStatement* pstmt = con->prepareStatement("SELECT content FROM messages WHERE id = ?");
    pstmt->setInt(1, message_id);

    sql::ResultSet* resultSet = pstmt->executeQuery();

    if (resultSet->next()) {
        std::string message_text = resultSet->getString("content");

        delete resultSet;
        delete pstmt;

        return message_text;
    }
    else {
        // Повідомлення з заданим id не знайдено
        delete resultSet;
        delete pstmt;
        throw std::exception();
    }
}

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

CUser CDatabase::get_user_by_id(int id)const {
    sql::PreparedStatement* pstmt = con->prepareStatement("SELECT id FROM users WHERE id = ?");
    pstmt->setInt(1, id);

    sql::ResultSet* resultSet = pstmt->executeQuery();

    if (resultSet->next()) {

        CUser user;

        std::memcpy(user.s_name, std::string(resultSet->getString("name")).c_str(), 50);
        std::memcpy(user.s_password, std::string(resultSet->getString("password")).c_str(), 50);
        user.i_picture = resultSet->getInt("avatar");

        delete resultSet;
        delete pstmt;

        return user;
    }
    else {
        // Користувач з заданим іменем не знайдений
        delete resultSet;
        delete pstmt;
        throw std::exception();
    }
}

std::vector<CChat> CDatabase::get_chats() const {
    std::vector<CChat> chats;

    sql::PreparedStatement* pstmt = con->prepareStatement("SELECT id, first_user_id, num_first_unread, second_user_id, num_second_unread, created_at FROM chats");
    sql::ResultSet* resultSet = pstmt->executeQuery();

    while (resultSet->next()) {
        CChat chat;
        chat.user1_id = resultSet->getInt("first_user_id");
        chat.unread1 = resultSet->getInt("num_first_unread");
        chat.user2_id = resultSet->getInt("second_user_id");
        chat.unread2 = resultSet->getInt("num_second_unread");
        chat.chat_id = resultSet->getInt("id");
        chat.user1 = this->get_user_by_id(chat.user1_id);
        chat.user2 = this->get_user_by_id(chat.user2_id);
        // Якщо created_at є рядком, не забудьте додати його обробку
        chats.push_back(chat);
    }

    delete resultSet;
    delete pstmt;
    return chats;
}



std::vector<CUser> CDatabase::get_users() const {
    std::vector<CUser> users;

    sql::PreparedStatement* pstmt = con->prepareStatement("SELECT   name, password, avatar  FROM users");
    sql::ResultSet* resultSet = pstmt->executeQuery();

    while (resultSet->next()) {
        CUser user_s;
        std::memcpy(user_s.s_name, std::string(resultSet->getString("name")).c_str(), sizeof(user_s.s_name));
       std::memcpy(user_s.s_password, std::string(resultSet->getString("password")).c_str(), sizeof(user_s.s_password));
       user_s.i_picture = resultSet->getInt("avatar");
      
        // Якщо created_at є рядком, не забудьте додати його обробку
        users.push_back(user_s);
    }

    delete resultSet;
    delete pstmt;
    return users;
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

void CDatabase::update_chat(CChat chat) const {
    int id = get_chat_id(chat);
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
    int chatId = chat.chat_id;
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
        std::memcpy(message.text, std::string(resultSet->getString("content")).c_str(), 1024);
        std::memcpy(message.created_at, std::string(resultSet->getString("created_at")).c_str(), 20);

        // Додавання повідомлення до вектора
        messages.push_back(message);
    }

    // Звільнення ресурсів
    delete pstmt;
    delete resultSet;
    return messages;
}