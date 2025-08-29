#include<iostream>
using namespace std;
class Message{
    public:
    virtual void getProduct()=0;
};
class TextMessage:public Message{
    public:
    void getProduct(){
        cout<<"Text Message"<<"\n";
    }
};
class JsonMessage:public Message{
    public:
    void getProduct(){
        cout<<"Json Message"<<"\n";
    }
};
class Factory{
    public:
    Message* getMessage(){
        Message* msg=createMessage();
        return msg;
    }
    virtual Message* createMessage()=0;
};
class JsonFactory:public Factory{
    Message* createMessage(){
        return new JsonMessage();
    }
};

class TextFactory:public Factory{
    Message* createMessage(){
        return new TextMessage();
    }
};
void printMessage(Factory* factory){
    Message* msg=factory->getMessage();
    msg->getProduct();
}
int main(){
    printMessage(new JsonFactory());
    printMessage(new TextFactory());
    return 0;
}