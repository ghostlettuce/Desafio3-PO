#include "../include/MsgManager.h"

//Getters
User MsgManager::GetUser(const std::string& mobile) const {
    for(auto u : users_){
        if (u.GetMobile() == mobile){
            return u;
        }
    }
    return {};
}

//Methods
void MsgManager::AddMsg(Msg *msg){
    messages_.push_back(msg);
}


void MsgManager::AddUser(const User& user) {
  users_.push_back(user);
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

void MsgManager::saveOnFileFilter(){
    std::string file, field;
    int opt;

    std::cout << "-- Save on File with Filters --" << std::endl << std::endl;

    std::cout << "File name: ";
    std::cin >> file;

    std::cout << "opt = 1: print the list of emails sent to a given email address: each line contains the information "
                 "about the sender and the text of the corresponding email;" << std::endl;

    std::cout << "opt = 2: print the list of emails sent by a given email address: each line contains the information "
                 "about the receiver and the text of the corresponding email;" << std::endl;

    std::cout << "opt = 3: print the list of mobile messages sent to a given phone number: each line contains the name "
                 "about the sender and the text of the corresponding message;" << std::endl;

    std::cout << "opt = 4: print the list of mobile messages received by a given phone number: each line contains the "
                 "name of the sender and the text of the corresponding message." << std::endl;

    std::cout << "Option: ";
    std::cin >> opt;

    std::cout << "Field of search: ";
    std::cin >> field;

    if (opt<1 || opt>4){
        throw std::invalid_argument ("MsgManager::SaveOnFileFilter - option not valid");
        return;
    }
    saveOnFileFilter(file, opt, field);
}

void MsgManager::saveOnFileFilter(const std::string& file, const int& opt,const std::string& field){





















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
