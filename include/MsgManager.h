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

#include <vector>
#include <map>

class MsgManager {

private:
    std::map<std::string, User> users_;
    /*
    std::vector<EmailMsg *> emails_;
    std::vector<TextMsg *> texts_;
     Delete the attributes used to store Mobile Messages and Emails and consider only a single data
structure to store messages that are created using dynamic memory allocation
     */

    std::vector <std:: string> messages_;



public:
    //Constructors
    MsgManager() = default;

    //Destructor
    ~MsgManager();

    //Getters
    [[nodiscard]] User GetUser(std::string& mobile) const;

    //Methods

    //polimorfismo
    void ToVector(EmailMsg message);
    void ToVector(TextMsg message);

    // Add text and email messages, and users.
    /*
     Delete member functions AddTextMsg and AddEmailMsg and implement a new method
AddMsg(Msg *msg)

    void AddEmailMsg(EmailMsg* message);
    void AddTextMsg(TextMsg* message);
    */

    void AddMsg(Msg *msg);

    void AddUser(const User& user);

    // Save on file the collected data.
    void SaveToFile(const std::string& filename);

    // Statistic methods.
    [[nodiscard]] double TextAverageSize() const;

    //Operators
    friend std::ostream &operator<<(std::ostream& os, const MsgManager& manager);

};

#endif //OOP_CLASSES_DESAFIOS_DESAFIO_2_MSGMANAGER_H_
