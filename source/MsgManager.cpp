#include "../include/MsgManager.h"

//Destructor
//the class must guarantee the release of this memory when the
//management system is destroyed
MsgManager::~MsgManager(){

delete [] messages_;

    while (!messages_.empty()){

        delete[] messages_;

        delete messages_.back();
        messages_.pop_back();

    }


}


//Getters

//Methods

void MsgManager::ToVector(EmailMsg message){
    messages_.push_back(message);

}
void MsgManager::ToVector(TextMsg message){
    messages_.push_back(message);
}



/*

void MsgManager::AddEmailMsg(EmailMsg *message) {
  emails_.push_back(message);
}

void MsgManager::AddTextMsg(TextMsg *message) {
  texts_.push_back(message);
}
 */


void MsgManager::AddMsg(Msg *msg){


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
