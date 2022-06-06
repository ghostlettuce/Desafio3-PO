#include "../include/Msg.h"

//Constructors
Msg::Msg(const std::string& body) : body_(body) {}

//Getters
const std::string& Msg::GetBody() const {
  return body_;
}

//Setters
void Msg::SetBody(const std::string& body) {

  MsgType a = this->GetType();
  if (this->GetType() == Mobile) {
      if (body.length() > 40) {
          throw std::invalid_argument("TextMsg::TextMsg - invalid Text Message Body too long");
      } else {
          body_ = body;
      }

  } else {
      body_ = body;
  }
}

//Operators
std::ostream& operator<<(std::ostream& os, const Msg& msg) {
  os << msg.body_;
  return os;
}

std::istream& operator>>(std::istream& is, Msg& msg) {
  is >> msg.body_;
  return is;
}
