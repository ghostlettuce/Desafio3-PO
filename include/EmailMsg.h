#ifndef OOP_CLASSES_DESAFIOS_DESAFIO_2_EMAILMSG_H_
#define OOP_CLASSES_DESAFIOS_DESAFIO_2_EMAILMSG_H_

#include <string>
#include <iostream>

#include "Msg.h"

class EmailMsg : public Msg {
private:
    static int number_of_mails_;
    int id_;
    std::string src_mail_;
    std::string dst_mail_;

public:
    //Constructors
    EmailMsg();
    explicit EmailMsg(const std::string& body);
    EmailMsg(const std::string& body, const std::string& src_mail, const std::string& dst_mail);

    //Getters
    [[nodiscard]] static int GetNumberOfMails();
    [[nodiscard]] int GetId() const;
    [[nodiscard]] const std::string& GetSrcMail() const;
    [[nodiscard]] const std::string& GetDstMail() const;
    [[nodiscard]] const MsgType GetType() override;

    //Setters
    void SetSrcMail(const std::string& src_mail);
    void SetDstMail(const std::string& dst_mail);

    //Methods
    std::string IsValidMail(const std::string& mail, const int& type);

    //Operators
    friend std::ostream& operator<<(std::ostream& os, const EmailMsg& msg);
    friend std::istream& operator>>(std::istream& is, EmailMsg& msg);

};

#endif //OOP_CLASSES_DESAFIOS_DESAFIO_2_EMAILMSG_H_
