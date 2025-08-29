#include<iostream>
using namespace std;
//eagar
class Wifi{
    string password;
    static Wifi* wifi;
    public:
    Wifi(string pwd){
        this->password=pwd;
        
    }
this->wifi=new Wifi("password");
    // network=new Wifi("password");
    public:
    Wifi* getInstance(){
        return wifi;
    }
    string getPassword(){
        return this->password;
    }
    void setPassword(string pwd){
        this->password=pwd;
    }
};
Wifi *Wifi::wifi=0;
// Wifi *Wifi::wifi=new Wifi("pa/ssword");;
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