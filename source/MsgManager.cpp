#include "../include/MsgManager.h"

//Getters
User MsgManager::GetUser(const std::string& field) const {

    if(field.at(0) == '+') {
        for (auto u: users_) {
            if (u.GetMobile() == field) {
                return u;
            }
        }
    } else {
        for (auto u: users_) {
            if (u.GetEmail() == field) {
                return u;
            }
        }
    }
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

void MsgManager::saveOnFileFilter(const std::string& file, const int& opt,const std::string& field) {

    std::ofstream fo(file);

    User user = GetUser(field);

    switch (opt){

        case 1:

            fo << "Emails sent to" << user.GetName() << " +++ " << field << " *** " << user.GetMobile() << std::endl;

            for (auto m : messages_) {

                EmailMsg *em = dynamic_cast<EmailMsg *>(m);
                if (em->GetType() == Msg::Email && em->GetDstMail() == field) {
                    fo << "    " << GetUser(em->GetSrcMail()).GetName() << " +++ " << em->GetSrcMail() << " *** "
                       << GetUser(em->GetSrcMail()).GetMobile() << " -> " << em->GetBody();
                }
            }
            break;

        case 2:

            fo << "Emails sent by" << user.GetName() << " +++ " << field << " *** " << user.GetMobile() << std::endl;

                for (auto m : messages_) {

                    EmailMsg *em = dynamic_cast<EmailMsg *>(m);
                    if (em->GetType() == Msg::Email && em->GetSrcMail() == field) {
                        fo << "    " << GetUser(em->GetDstMail()).GetName() << " +++ " << em->GetDstMail() << " *** "
                           << GetUser(em->GetDstMail()).GetMobile() << " -> " << em->GetBody();
                    }
                }
                break;

        case 3:

            fo << "Text messages sent to" << user.GetName() << " +++ " << user.GetEmail()<< " *** " << field << std::endl;

            for (auto m : messages_) {

                TextMsg *tm = dynamic_cast<TextMsg *>(m);
                if (tm->GetType() == Msg::Mobile && tm->GetSrcPhoneNo() == field) {
                    fo << "    " << GetUser(tm->GetSrcPhoneNo()).GetName() << " +++ " << GetUser(tm->GetSrcPhoneNo()).GetEmail()<< " *** "
                       << tm->GetSrcPhoneNo()<< " -> " << tm->GetBody();
                }
            }
            break;

        case 4:
            fo << "Text messages sent by" << user.GetName() << " +++ " << field << " *** " << user.GetMobile() << std::endl;

            for (auto m : messages_) {

                TextMsg *tm = dynamic_cast<TextMsg *>(m);
                if (tm->GetType() == Msg::Email && tm->GetDstPhoneNo() == field) {
                    fo << "    " << GetUser(tm->GetDstPhoneNo()).GetName() << " +++ " << GetUser(tm->GetDstPhoneNo()).GetEmail() << " *** "
                       << tm->GetDstPhoneNo() << " -> " << tm->GetBody();
                }
            }
            break;


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
