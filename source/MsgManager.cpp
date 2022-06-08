#include "../include/MsgManager.h"

//Getters
User MsgManager::GetUser(const std::string& mobile) const {
    for(auto u : users_){
        if (u.GetMobile() == mobile){
            return u;
        }
    }
}

//Methods
void MsgManager::AddMsg(Msg *msg){
    messages_.push_back(msg);
}


void MsgManager::AddUser(const User& user) {
  users_[user.GetEmail()] = user;
}

void MsgManager::SaveToFile(const std::string& filename) {
  std::ofstream file(filename);

  for (auto[email, user] : users_) {
    file << "user " << user.GetName() << " " << user.GetMobile() << " " << user.GetEmail() << std::endl;
  }

  for (const auto& email : emails_) {
    file << "email " << email->GetSrcMail() << " " << email->GetDstMail() << " " << email->GetBody() << std::endl;
  }

  for (const auto& text : texts_) {
    file << "text " << text->GetSrcPhoneNo() << " " << text->GetDstPhoneNo() << " " << text->GetBody() << std::endl;
  }

  file.close();
}

double MsgManager::TextAverageSize() const {
  double sum = 0.0;
  for (const auto& text : texts_) {
    sum += text->GetBody().length();
  }

  return sum / texts_.size();
}

void MsgManager::ChangeMobile(const User& user, const std::string& new_mobile){
    for(auto u : users_){
        if (u.GetMobile() == user.GetMobile()){
            u.SetMobile(new_mobile);
        }
    }
}

//Operators
std::ostream& operator<<(std::ostream& os, const MsgManager& manager) {
  os << "Users List (sorted by email):" << std::endl;
  for (const auto&[email, user] : manager.users_) {
    os << "\t" << user << std::endl;
  }

  os << "Email Messages List:" << std::endl;
  for (const auto& email : manager.emails_) {
    os << "\t" << *email << std::endl;
  }

  os << "Text Message List:" << std::endl;
  for (const auto& text : manager.texts_) {
    os << "\t" << *text << std::endl;
  }

  os << "Text Average Size: " << manager.TextAverageSize() << std::endl;

  return os;
}
