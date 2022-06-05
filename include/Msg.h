#ifndef OOP_CLASSES_DESAFIOS_DESAFIO_2_MSG_H_
#define OOP_CLASSES_DESAFIOS_DESAFIO_2_MSG_H_

#include <string>
#include <iostream>

class Msg {
 private:
    std::string body_;

 public:
    Msg() = default;
    Msg(const std::string &body);
    const std::string &GetBody() const;
    void SetBody(const std::string &body);
    friend std::ostream &operator<<(std::ostream &os, const Msg &msg);
    friend std::istream &operator>>(std::istream &os, Msg &msg);

};

#endif //OOP_CLASSES_DESAFIOS_DESAFIO_2_MSG_H_
