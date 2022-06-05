#include "../include/User.h"

//Constructors
User::User(const std::string& name, const std::string& email,
           const std::string& mobile)
    : name_(name), email_(email), mobile_(mobile) {}

//Getters
const std::string& User::GetName() const {
  return name_;
}

const std::string& User::GetEmail() const {
    return email_;
}

const std::string& User::GetMobile() const {
    return mobile_;
}

//Setters
void User::SetName(const std::string& name) {
  name_ = name;
}

void User::SetEmail(const std::string& email) {
  email_ = email;
}

void User::SetMobile(const std::string& mobile) {
  mobile_ = mobile;
}

//Operators
std::ostream& operator<<(std::ostream& os, const User& user) {
  os << user.name_ << " +++ " << user.email_ << " *** " << user.mobile_;
  return os;
}

std::istream& operator>>(std::istream& is, User& user) {
  is >> user.name_ >> user.email_ >> user.mobile_;
  return is;
}

