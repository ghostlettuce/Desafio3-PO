#include <iostream>
#include <fstream>
#include "include/User.h"
#include "include/Msg.h"
#include "include/EmailMsg.h"
#include "include/TextMsg.h"
#include "include/MsgManager.h"

using namespace std;

void Part2();

void Part3();

int main() {
    cout << "*** Part 1 ***" << endl << endl;

    Msg::MsgType t = Msg::MsgType::Mobile;
    cout << "Type mobile: " << t << endl;
    t = Msg::MsgType::Email;
    cout << "Type email: " << t << endl << endl;

    Msg *m = new TextMsg("I love programming.", "+351234370555", "+351234370500");
    cout << m->GetType() << endl;

    cout << *m << endl; // print as a message
    TextMsg *mm = dynamic_cast<TextMsg*>(m);
    cout << *mm << endl << endl; // print as mobile message

    m = new EmailMsg("I am ready :-)", "a@ua.pt", "m@ua.pt");
    cout << m->GetType() << endl;
    cout << *m << endl;
    EmailMsg *em = dynamic_cast<EmailMsg*>(m);
    cout << *em << endl << endl;

    TextMsg *ptr = dynamic_cast<TextMsg*>(m);
    if(ptr == nullptr){
        cout << "ERROR: an email message is not a mobile message!" << endl << endl;
    }

    User u;
    try{
        u.SetEmail("abc.xyz");
    }catch (invalid_argument const &e){
        cout << "ERROR: " << e.what() << endl << endl;
    }

    try{
        u.SetMobile("910123");
    }catch (invalid_argument const &e){
        cout << "ERROR: " << e.what() << endl << endl;
    }

    try{
        m = new TextMsg("I love programming really, really, really  a lot.", "+351234370555", "+351234371254");
    }catch (invalid_argument const &e){
        cout << "ERROR: " << e.what() << endl << endl;
    }

    try{
        m = new EmailMsg("I am ready :-)", "ua.pt", "m@ua.pt");
    }catch (invalid_argument const &e){
        cout << "ERROR: " << e.what() << endl << endl;
    }

    cout << *m << endl; // old m pointer

    //Part2();

    //Part3();
}

/*void Part2(){
    cout << endl << "*** Part 2 ***" << endl << endl;
    MsgManager m;

    m.AddUser(User("Maria", "maria@ua.pt", "+351234370500"));
    m.AddUser(User("Ana", "ana@ua.pt", "+351234370555"));
    m.AddUser(User("Ze", "ze@ua.pt", "+351234234234"));
    m.AddUser(User("Joao", "joao@ua.pt", "+351234370111"));
    m.AddUser(User("Rita", "rita@ua.pt", "+351234370000"));

    m.AddMsg(new EmailMsg("The PpO challenge is today!", "maria@ua.pt", "ana@ua.pt"));
    m.AddMsg(new EmailMsg("I am ready!", "ana@ua.pt", "maria@ua.pt"));
    m.AddMsg(new TextMsg("PpO challenge is indeed today!", "+351234370000", "+351234370111"));
    m.AddMsg(new EmailMsg("The content is what I studied.", "ana@ua.pt", "ze@ua.pt"));
    m.AddMsg(new TextMsg("I love programming.", "+351234370555", "+351234370500"));
    m.AddMsg(new EmailMsg("Classes and objects...", "ze@ua.pt", "maria@ua.pt"));
    m.AddMsg(new TextMsg("How was the challenge?", "+351234370000", "+351234234234"));
    m.AddMsg(new TextMsg("I love programming.", "+351234370555", "+351234234234"));
    cout << m << endl;

    m.saveOnFileFilter("../m1.txt",1,"maria@ua.pt");
    m.saveOnFileFilter("../m2.txt",2,"ana@ua.pt");
    m.saveOnFileFilter("../m3.txt",3,"+351234370500");
    m.saveOnFileFilter("../m4.txt",4,"+351234370555");

    User u = m.GetUser("+351234370500");
    cout << u << endl;
    m.ChangeMobile(u,"+351234370501");
    cout << m.GetUser("+351234370501") << endl;
}

void Part3(){
    cout << endl << "*** Part 3 ***" << endl;
    MsgManager m;

    m.loadLoadMessagesFromFile("../messages01.txt");

    cout << m << endl;
}*/