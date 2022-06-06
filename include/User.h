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
    //Constructors
    User() = default;
    User(const std::string& name, const std::string& email,
         const std::string& mobile);

    //Getters
    [[nodiscard]] const std::string& GetName() const;
    [[nodiscard]] const std::string& GetEmail() const;
    [[nodiscard]] const std::string& GetMobile() const;

    //Setters
    void SetName(const std::string& name);
    void SetEmail(const std::string& email);
    void SetMobile(const std::string& mobile);

    //Method
    [[nodiscard]] std::string IsValidMail(const std::string& mail, const int& type);
    [[nodiscard]] std::string IsValidMobile(const std::string& mobile, const int& type);

    //Operators
    friend std::ostream& operator<<(std::ostream& os, const User& user);
    friend std::istream& operator>>(std::istream& os, User& user);
};

#endif  // OOP_CLASSES_USER_H
