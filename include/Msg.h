#ifndef OOP_CLASSES_DESAFIOS_DESAFIO_2_MSG_H_
#define OOP_CLASSES_DESAFIOS_DESAFIO_2_MSG_H_

#include <string>
#include <iostream>
#include <stdexcept>

class Msg {
private:
    std::string body_;

public:
    //Attributes
    enum MsgType {Mobile, Email};

    //Operators
    Msg() = default;
    explicit Msg(const std::string& body);

    //Getters
    [[nodiscard]] const std::string& GetBody() const;
    [[nodiscard]] virtual const MsgType GetType() = 0;

    //Setters
    void SetBody(const std::string& body);

    //Operators
    friend std::ostream& operator<<(std::ostream& os, const Msg& msg);
    friend std::istream& operator>>(std::istream& os, Msg& msg);

};

#endif //OOP_CLASSES_DESAFIOS_DESAFIO_2_MSG_H_
