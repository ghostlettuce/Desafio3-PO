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
          throw "ERROR: TextMsg::TextMsg - invalid Text Message Body too long";
      }
      
      try {
          body_ = body;
      } catch (const char* err_msg) {
          std::cerr << err_msg << std::endl;
          SetBody(body.substr(0, 40));
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
