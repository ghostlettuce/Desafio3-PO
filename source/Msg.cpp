#include "../include/Msg.h"

Msg::Msg(const std::string &body) : body_(body) {}

const std::string &Msg::GetBody() const {
  return body_;
}

void Msg::SetBody(const std::string &body) {
  body_ = body;
}

std::ostream &operator<<(std::ostream &os, const Msg &msg) {
  os << msg.body_;
  return os;
}

std::istream &operator>>(std::istream &is, Msg &msg) {
  is >> msg.body_;
  return is;
}
