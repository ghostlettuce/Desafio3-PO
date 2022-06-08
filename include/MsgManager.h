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
    std::vector <Msg *> messages_;

public:
    //Constructors
    MsgManager() = default;

    //Destructor
    ~MsgManager() = default;

    //Getters
    [[nodiscard]] User GetUser(std::string& mobile) const;

    //Methods
    void AddMsg(Msg* message);
    void AddUser(const User& user);
    void SaveToFile(const std::string& filename);

    // Statistic methods.
    [[nodiscard]] double TextAverageSize() const;

    //Operators
    friend std::ostream &operator<<(std::ostream& os, const MsgManager& manager);

};

#endif //OOP_CLASSES_DESAFIOS_DESAFIO_2_MSGMANAGER_H_
