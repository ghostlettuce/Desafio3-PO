#include "../include/MsgManager.h"

//Getters
const User& MsgManager::GetUser(const std::string& field) const {

    if(field.at(0) == '+') {
        for (auto& u: users_) {
            if (u.GetMobile() == field) {
                return u;
            }
        }
    } else {
        for (auto& u: users_) {
            if (u.GetEmail() == field) {
                return u;
            }
        }
    }

    //return  NULL;
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
    int mobile_size = 0;

    for (const auto& text : messages_) {
        if (text->GetType() == Msg::Mobile) {
            sum += text->GetBody().length();
            mobile_size++;
        }
    }

  return sum / mobile_size;
}

void MsgManager::ChangeMobile(const User& user, const std::string& new_mobile){
    for(auto& u : users_){
        if (u.GetMobile() == user.GetMobile()){
            u.SetMobile(new_mobile);
            return;
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
    }
    saveOnFileFilter(file, opt, field);
}

void MsgManager::saveOnFileFilter(const std::string& file, const int& opt,const std::string& field) {

    std::ofstream fo(file);

    User user = GetUser(field);

    switch (opt){

        case 1:

            fo << "Emails sent to " << user.GetName() << " +++ " << field << " *** " << user.GetMobile() << std::endl;

            for (auto m : messages_) {
                if (m->GetType() == Msg::Email) {
                    auto *em = dynamic_cast<EmailMsg *>(m);
                    if (em->GetDstMail() == field) {
                        fo << "    " << GetUser(em->GetSrcMail()).GetName() << " +++ " << em->GetSrcMail() <<
                            " *** " << GetUser(em->GetSrcMail()).GetMobile() << " -> " << em->GetBody()
                            << std::endl;
                    }
                }
            }
            break;

        case 2:

            fo << "Emails sent by " << user.GetName() << " +++ " << field << " *** " << user.GetMobile() << std::endl;

                for (auto m : messages_) {
                    if (m->GetType() == Msg::Email) {
                        auto *em = dynamic_cast<EmailMsg *>(m);
                        if (em->GetSrcMail() == field) {
                            fo << "    " << GetUser(em->GetDstMail()).GetName() << " +++ " << em->GetDstMail()
                               << " *** "
                               << GetUser(em->GetDstMail()).GetMobile() << " -> " << em->GetBody() << std::endl;
                        }
                    }
                }
                break;

        case 3:

            fo << "Text messages sent to " << user.GetName() << " +++ " << user.GetEmail()<< " *** " << field << std::endl;

            for (auto m : messages_) {

                if (m->GetType() == Msg::Mobile) {
                    auto *tm = dynamic_cast<TextMsg *>(m);
                    if (tm->GetDstPhoneNo() == field) {
                        fo << "    " << GetUser(tm->GetSrcPhoneNo()).GetName() << " +++ "
                           << GetUser(tm->GetSrcPhoneNo()).GetEmail() << " *** "
                           << tm->GetSrcPhoneNo() << " -> " << tm->GetBody() << std::endl;
                    }
                }
            }
            break;

        case 4:
            fo << "Text messages sent by " << user.GetName() << " +++ " << field << " *** " << user.GetMobile()
            << std::endl;

            for (auto m : messages_) {

                if (m->GetType() == Msg::Mobile) {
                    auto *tm = dynamic_cast<TextMsg *>(m);
                    if (tm->GetSrcPhoneNo() == field) {
                        fo << "    " << GetUser(tm->GetDstPhoneNo()).GetName() << " +++ "
                           << GetUser(tm->GetDstPhoneNo()).GetEmail() << " *** " << tm->GetDstPhoneNo() << " -> "
                           << tm->GetBody() << std::endl;
                    }
                }
            }
            break;

        default:
            return;
    }
}

void MsgManager::LoadMessagesFromFile(const std::string &filename){
    std::string file_entry;
    std::vector<std::string> file_entry_separeted;

    std::ifstream file (filename);

    while (file.good()) {
        std::getline(file, file_entry);

        file_entry_separeted = CharSeparated(file_entry);

        if (file_entry_separeted.at(0) == "user") {

            AddUser(User(file_entry_separeted.at(1), file_entry_separeted.at(2),
                         file_entry_separeted.at(3)));

        } else if (file_entry_separeted.at(0) == "mobile") {
            AddMsg(new TextMsg(file_entry_separeted.at(3), file_entry_separeted.at(1),
                                            file_entry_separeted.at(2)));

        } else if (file_entry_separeted.at(0) == "email"){
            AddMsg(new EmailMsg(file_entry_separeted.at(3), file_entry_separeted.at(1),
                                             file_entry_separeted.at(2)));
        }

    }

    file.close();
}

std::vector<std::string> MsgManager::CharSeparated(const std::string &initial_str) {
    std::string delimiter = " ";
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    for (int i = 0; i < 3; i++){
        pos_end = initial_str.find (delimiter, pos_start);
        token = initial_str.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    pos_end = initial_str.find ("\r", pos_start);
    token = initial_str.substr (pos_start, pos_end - pos_start);
    res.push_back (token);

    return res;
}

//Operators
std::ostream& operator<<(std::ostream& os, const MsgManager& manager) {
    os << "Users List (sorted by email):" << std::endl;
    for (const auto& user : manager.users_) {
        os << "\t" << user << std::endl;
    }

    os << "Email Messages List:" << std::endl;
    for (const auto& email : manager.messages_) {
        if (email->GetType() == Msg::Email){
            auto *em = dynamic_cast<EmailMsg *>(email);
            os << "\t" << *em << std::endl;
        }
    }

    os << "Text Message List:" << std::endl;
    for (const auto& text : manager.messages_) {
        if (text->GetType() == Msg::Mobile){
            auto *tm = dynamic_cast<TextMsg *>(text); 
            os << "\t" << *tm << std::endl;
        }
    }

    os << "Text Average Size: " << manager.TextAverageSize() << std::endl;

    return os;
}
