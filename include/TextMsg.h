#ifndef OOP_CLASSES_DESAFIOS_DESAFIO_2_TEXTMSG_H_
#define OOP_CLASSES_DESAFIOS_DESAFIO_2_TEXTMSG_H_

#include <string>
#include <iostream>

#include "Msg.h"

class TextMsg : public Msg {

private:
    const static int kMessageMaxLength = 30;
    static int number_of_texts_;
    int id_;
    std::string src_phone_no_;
    std::string dst_phone_no_;

public:
    //Constructors
    TextMsg();
    TextMsg(const std::string& body, const std::string& src_phone_no, const std::string& dst_phone_no);

    //Getters
    [[nodiscard]] static int GetNumberOfTexts();
    [[nodiscard]] const std::string& GetSrcPhoneNo() const;
    [[nodiscard]] const std::string& GetDstPhoneNo() const;
    [[nodiscard]] const kMsgType GetType() override;
    
    //Setters
    void SetSrcPhoneNo(const std::string& src_phone_no);
    void SetDstPhoneNo(const std::string& dst_phone_no);
    
    //Operators
    friend std::ostream& operator<<(std::ostream& os, const TextMsg& msg);
    friend std::istream& operator>>(std::istream& is, TextMsg& msg);
};

#endif //OOP_CLASSES_DESAFIOS_DESAFIO_2_TEXTMSG_H_
