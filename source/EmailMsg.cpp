#include "../include/EmailMsg.h"

int EmailMsg::number_of_mails_ = 1;

//Constructors
EmailMsg::EmailMsg() {
  id_ = number_of_mails_++;
}

EmailMsg::EmailMsg(const std::string& body)
        : Msg(body) {
    id_ = number_of_mails_++;
}

EmailMsg::EmailMsg(const std::string& body, const std::string& src_mail, const std::string& dst_mail)
    : Msg(body) {
    dst_mail_ = IsValidMail(dst_mail, 1);
    src_mail_ = IsValidMail(src_mail, 0);

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

const Msg::MsgType EmailMsg::GetType() {
    return Email;
}

//Setters
void EmailMsg::SetSrcMail(const std::string& src_mail) {
    src_mail_ = IsValidMail(src_mail, 2);
}

void EmailMsg::SetDstMail(const std::string& dst_mail) {
    dst_mail_ = IsValidMail(dst_mail, 3);
}

//Methods
std::string EmailMsg::IsValidMail(const std::string& mail, const int& type){
    int pos_1=mail.find('@');
    int pos_2=mail.find(".pt");
    int pos_3=mail.find(".com");

    if ( pos_1>0 && (pos_2>0 || pos_3>0) ){
        return mail;
    } else {
        switch (type) {
            case 0: // construtor src
                throw std::invalid_argument("EmailMsg::EmailMsg - invalid src_email address");
                break;

            case 1: // construtor dst
                throw std::invalid_argument("EmailMsg::EmailMsg - invalid dst_email address");
                break;

            case 2: // set src
                throw std::invalid_argument("EmailMsg::SetSrcMail - invalid src_email address");
                break;

            case 3: // set dst
                throw std::invalid_argument("EmailMsg::SetDstMail - invalid dst_email address");
                break;

            default:
                throw std::invalid_argument("Oopsi");
                break;
        }
    }
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

