#ifndef OOP_CLASSES_DESAFIOS_DESAFIO_2_MSGMANAGER_H_
#define OOP_CLASSES_DESAFIOS_DESAFIO_2_MSGMANAGER_H_

#include <map>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <ostream>

#include "User.h"
#include "Msg.h"
#include "EmailMsg.h"
#include "TextMsg.h"

class MsgManager {

 private:
    std::map<std::string, User> users_;
    std::vector<EmailMsg *> emails_;
    std::vector<TextMsg *> texts_;

public:
    MsgManager() = default;

    // Add text and email messages, and users.
    void AddEmailMsg(EmailMsg *message);
    void AddTextMsg(TextMsg *message);
    void AddUser(const User &user);

    // Save on file the collected data.
    void SaveToFile(const std::string &filename);

    // Statistic methods.
    double TextAverageSize() const;

    friend std::ostream &operator<<(std::ostream &os, const MsgManager &manager);

};

#endif //OOP_CLASSES_DESAFIOS_DESAFIO_2_MSGMANAGER_H_
