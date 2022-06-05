#include "../include/User.h"

User::User(const std::string& name, const std::string& email,
           const std::string& mobile)
    : name_(name), email_(email), mobile_(mobile) {}

const std::string &User::GetName() const {
  return name_;
}
void User::SetName(const std::string &name) {
  name_ = name;
}
const std::string &User::GetEmail() const {
  return email_;
}
void User::SetEmail(const std::string &email) {
  email_ = email;
}
const std::string &User::GetMobile() const {
  return mobile_;
}
void User::SetMobile(const std::string &mobile) {
  mobile_ = mobile;
}
std::ostream &operator<<(std::ostream &os, const User &user) {
  os << user.name_ << " +++ " << user.email_ << " *** " << user.mobile_;
  return os;
}
std::istream& operator>>(std::istream& is, User& user) {
  is >> user.name_ >> user.email_ >> user.mobile_;
  return is;
}

