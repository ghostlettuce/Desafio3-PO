#include "TextMsg.h"

int TextMsg::number_of_texts_ = 50;

TextMsg::TextMsg() {
  id_ = number_of_texts_++;
}

TextMsg::TextMsg(const std::string &body, const std::string &src_phone_no, const std::string &dst_phone_no)
    : Msg(), src_phone_no_(src_phone_no), dst_phone_no_(dst_phone_no) {
  if (body.length() > TextMsg::kMessageMaxLength) {
    SetBody(body.substr(0, TextMsg::kMessageMaxLength));
  } else {
    SetBody(body);
  }
  id_ = number_of_texts_++;
}

int TextMsg::GetNumberOfTexts() {
  return number_of_texts_;
}

const std::string &TextMsg::GetSrcPhoneNo() const {
  return src_phone_no_;
}

const std::string &TextMsg::GetDstPhoneNo() const {
  return dst_phone_no_;
}

void TextMsg::SetSrcPhoneNo(const std::string &src_phone_no) {
  src_phone_no_ = src_phone_no;
}

void TextMsg::SetDstPhoneNo(const std::string &dst_phone_no) {
  dst_phone_no_ = dst_phone_no;
}

std::ostream &operator<<(std::ostream &os, const TextMsg &msg) {
  os << "Text Msg " << msg.id_ << " from " << msg.src_phone_no_ << " to " << msg.dst_phone_no_ << " with content: "
     << static_cast<const Msg &>(msg);
  return os;
}

std::istream &operator>>(std::istream &is, TextMsg &msg) {
  std::string message_body;
  is.ignore();
  std::getline(is, message_body);
  if (message_body.length() > TextMsg::kMessageMaxLength) {
    msg.SetBody(message_body.substr(0, TextMsg::kMessageMaxLength));
  } else {
    msg.SetBody(message_body);
  }
  is >> msg.src_phone_no_ >> msg.dst_phone_no_;
  return is;
}
