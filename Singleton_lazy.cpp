#include<iostream>
using namespace std;
// Lazy singleton: only create instance when it is needed 
class Wifi{
    string password;
    static Wifi* wifi;
    Wifi(string pwd){
        this->password=pwd;
    }
    public:
    Wifi* getInstance(){
        if(wifi==NULL){
            this->wifi=new Wifi("password");
        }
        return this->wifi;
    }
    string getPassword(){
        return this->password;
    }
    void setPassword(string pwd){
        this->password=pwd;
    }
};
Wifi *Wifi::wifi=0;
int main(){
    Wifi* c1;
    c1=c1->getInstance();
    Wifi* c2;
    c2=c2->getInstance();
    cout<<"Print Default password of C1,C2 user"<<"\n";
    cout<<c1->getPassword()<<"\n";
    cout<<c2->getPassword()<<"\n";
    cout<<"c1 user update password"<<"\n";
    c1->setPassword("123Passwordc1");
    cout<<"Print updated password of C1,C2 user"<<"\n";
    cout<<c1->getPassword()<<"\n";
    cout<<c2->getPassword()<<"\n";
    return 0;
}