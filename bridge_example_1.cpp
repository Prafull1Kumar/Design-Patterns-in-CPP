#include<iostream>
using namespace std;
class NotificationSender{
    public:
    virtual void sendNotification()=0;
    // void sendNotification(){
    //     cout<<"Initial send Notification function"<<"\n";
    //     return ;
    // }

};
class Email:public NotificationSender{
    public:
    void sendNotification(){
        cout<<"Notification is send thought email"<<"\n";
        return ;
    }
};
class SMS:public NotificationSender{
    public:
    void sendNotification(){
        cout<<"Notification is send thought SMS"<<"\n";
        return ;
    }
};
class NotificationType{
    public:
    virtual void sendMessage()=0;
};
class Text:public NotificationType{ 
    NotificationSender* method;
    public:
    Text(NotificationSender* n):method(n){}
    
    void sendMessage(){
        cout<<"This message is text"<<"\n";
        method->sendNotification();
    }
};
class QRCode:public NotificationType{
    NotificationSender* method;
    public:
    QRCode(NotificationSender* n):method(n){}
    
    void sendMessage(){
        cout<<"This message in QR Code based"<<"\n";
        method->sendNotification();
    }
};
int main(){
    NotificationSender* email=new Email();
    NotificationSender* sms=new SMS();
    NotificationType* text_email=new Text(email);
    NotificationType* text_sms=new Text(sms);
    NotificationType* qrcode_email=new QRCode(email);
    NotificationType* qrcode_sms=new QRCode(sms);
    text_email->sendMessage();
    text_sms->sendMessage();
    qrcode_email->sendMessage();
    qrcode_email->sendMessage();
    return 0;
}