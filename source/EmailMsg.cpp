#include "../include/EmailMsg.h"

int EmailMsg::number_of_mails_ = 0;

//Constructors
EmailMsg::EmailMsg() {
  id_ = number_of_mails_++;
}

EmailMsg::EmailMsg(const std::string& body)
        : Msg(body) {
    id_ = number_of_mails_++;
}

EmailMsg::EmailMsg(const std::string& body, const std::string& src_mail, const std::string& dst_mail)
    : Msg(body), src_mail_(src_mail), dst_mail_(dst_mail) {
  id_ = number_of_mails_++;
}

//Getters
int EmailMsg::GetNumberOfMails() {
  return number_of_mails_;
}

int EmailMsg::GetId() const {
  return id_;
}

const std::string& EmailMsg::GetSrcMail() const {
  return src_mail_;
}

const std::string& EmailMsg::GetDstMail() const {
  return dst_mail_;
}

const kMsgType EmailMsg::GetType() {
    return email;
}

//Setters
void EmailMsg::SetSrcMail(const std::string& src_mail) {
  src_mail_ = src_mail;
}

void EmailMsg::SetDstMail(const std::string& dst_mail) {
  dst_mail_ = dst_mail;
}

//Operators
std::ostream& operator<<(std::ostream& os, const EmailMsg& msg) {
  os << "Email " << msg.id_ << " from " << msg.src_mail_ << " to " << msg.dst_mail_ << " with content: "
     << static_cast<const Msg& >(msg);
  return os;
}

std::istream& operator>>(std::istream& is, EmailMsg& msg) {
  std::string message_body;
  is.ignore();
  std::getline(is, message_body);
  msg.SetBody(message_body);
  is >> msg.src_mail_ >> msg.dst_mail_;
  return is;
}

