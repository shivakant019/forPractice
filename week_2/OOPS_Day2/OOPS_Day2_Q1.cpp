#include<bits/stdc++.h>
using namespace std;

//Abstract Class
class App{
    void startApp() = 0;
    void closeApp() = 0;
};

//Abstract Class
class StatusServices{
public:
    virtual void seeStatus() = 0;
    virtual void deleteStatus() = 0;
    virtual void seeStatus() = 0;
    virtual void setStatus() = 0;
};

//Abstract Class
class MessageServices{
    virtual void sendMessage() = 0;
};


//Abstract Class
class ChatServices{
public:
    virtual void sendChat() = 0;
    virtual void reciveChat() = 0;
};

//Abstract Class
class ContactServices{
public:
    virtual void addContact(string,int){}
    virtual int getContact(string){}
    virtual void deleteConatact(){}
};

//Abstract Class
class Type{
    string TEXT;
    string IMAGE;
    string AUDIO;
    string VIDEO;
};


class Status : StatusServices{
    Type type
    string status;

};


class Contact : ContactServices{
    string name;
    int mobileNumber;
};

class Message : MesageServices{

    Type type;
    string content;
};

class Status : StatusService{
    string status;
public:
    void setStatus() = 0;
};


class User{
    Contact contact;
    Message message;
    Status status;
public:
    void chatWithAnotherPerson(this,Contact);

};

class Chat : ChatService{
    User sender;
    User reciver;Abstract Class
};

//WhatApp inherits App
class WhatsApp : App{
    Chat user;
    vector<User> chatList;
public:
    void startChat(){}
    void endChat(){}
    void myChatList(){}

};
