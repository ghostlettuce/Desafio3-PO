#ifndef OOP_CLASSES_USER_H
#define OOP_CLASSES_USER_H

#include <string>
#include <iostream>

class User {
 private:
    std::string name_;
    std::string email_;
    std::string mobile_;

public:
    User() = default;
    User(const std::string& name, const std::string& email,
         const std::string& mobile);
    const std::string &GetName() const;
    void SetName(const std::string &name);
    const std::string &GetEmail() const;
    void SetEmail(const std::string &email);
    const std::string &GetMobile() const;
    void SetMobile(const std::string &mobile);
    friend std::ostream &operator<<(std::ostream &os, const User &user);
    friend std::istream &operator>>(std::istream &os, User &user);
};

#endif  // OOP_CLASSES_USER_H
