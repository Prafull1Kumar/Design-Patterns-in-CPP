#include<iostream>
using namespace std;
class Message{
    public:
    virtual string getContent()=0;
};
class TextMessage:public Message{
    string text;
    public:
    TextMessage(string txt){
        this->text=txt;
    }
    string getContent(){
        return this->text;
    }
};
class HtmlMessage:public Message{
    Message* htmlmsg;
    public:
    HtmlMessage(Message* msg){
        this->htmlmsg=msg;
    }
    string getContent(){
        return "HTML("+htmlmsg->getContent()+")";
    }
};
class Base64Message:public Message{
    Message* htmlmsg;
    public:
    Base64Message(Message* msg){
        this->htmlmsg=msg;
    }
    string getContent(){
        return "Base64("+htmlmsg->getContent()+")";
    }
};
int main(){
    Message* txt=new TextMessage("Normal Text Message");
    Message* html=new HtmlMessage(txt);
    cout<<html->getContent()<<"\n";
    Message* base64=new Base64Message(txt);
    cout<<base64->getContent()<<"\n";
    return 0;
}