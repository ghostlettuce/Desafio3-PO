#include "../include/User.h"

//Constructors
User::User(const std::string& name, const std::string& email,
           const std::string& mobile)
    : name_(name), mobile_(mobile) {
    email_ = IsValidMail(email, 0);
    mobile_ = IsValidMobile(mobile, 0);
}

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
    email_ = IsValidMail(email, 1);
}

void User::SetMobile(const std::string& mobile) {
    mobile_ = IsValidMobile(mobile, 1);
}

//Method
std::string User::IsValidMail(const std::string& mail, const int& type){
    int pos_at = mail.find('@');
    int pos_at2 = mail.find('@', pos_at + 1);

    int pos_pt = mail.find(".pt");
    int pos_pt2 = mail.find(".pt", pos_pt + 1);

    int pos_com = mail.find(".com");
    int pos_com2 = mail.find(".com", pos_com + 1);

    int s = size(mail);

    if ( pos_at > 0 && (s - 3 == pos_pt) || (s - 4 == pos_com) && (pos_at2 + pos_pt2 + pos_com2) < 0 ){
        return mail;
    } else {
        switch (type) {
            case 0: // construtor
                throw std::invalid_argument("User::User - invalid email address");

            case 1: // setter
                throw std::invalid_argument("User::SetEmail - invalid email address");

            default:
                throw std::invalid_argument("Oopsi");
        }
    }
}

std::string User::IsValidMobile(const std::string& mobile, const int& type){
    int pos=mobile.find("+351");

    if (pos>=0 && mobile.size()==13){
        return mobile;
    } else {
        switch (type) {
            case 0: // constructor
                throw std::invalid_argument("User::User - invalid number");

            case 1: // setter
                throw std::invalid_argument("User::SetMobile - invalid number");

            default:
                throw std::invalid_argument("Oopsi");
        }
    }
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

bool User::operator < (const User& user) const{
    return (email_ < user.email_);
}