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
    std::vector<User> users_;
    std::vector<Msg *> messages_;

public:
    //Constructors
    MsgManager() = default;

    //Destructor
    ~MsgManager() = default;

    //Getters
    [[nodiscard]] User GetUser(const std::string& mobile) const;


    //Methods
    void AddMsg(Msg* message);
    void AddUser(const User& user);
    void ChangeMobile(const User& u, const std::string& new_mobile);
    void saveOnFileFilter();
    void saveOnFileFilter(const std::string& file, const int& opt,const std::string& field);

    // Statistic methods.
    [[nodiscard]] double TextAverageSize() const;

    void LoadMessagesFromFile(const std::string &filename);
    std::vector<std::string> CharSeparated(const std::string &initial_str, const std::string &delimiter)

    //Operators
    friend std::ostream &operator<<(std::ostream& os, const MsgManager& manager);

};

#endif //OOP_CLASSES_DESAFIOS_DESAFIO_2_MSGMANAGER_H_
