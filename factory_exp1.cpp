#include<iostream>
using namespace std;
class DatingApp{
    public:
    virtual void getGirls()=0;
};
class Tinder:public DatingApp{
    public:
    void getGirls(){
        cout<<"Lists of girls from Tinder"<<"\n";
    }
};
class Hinge:public DatingApp{ 
    public:
    void getGirls(){
        cout<<"Lists of Girls from Hinge"<<"\n";
    }
};
class MobileAppFactory{ 
    public:
    DatingApp* getApp(){
        DatingApp* app=createApp();
        return app;
    }
    virtual DatingApp* createApp()=0;
};
class TinderMobileAppFactory:public MobileAppFactory{
    DatingApp* createApp(){
        return new Tinder();
    }
};
class HingeMobileAppFactory:public MobileAppFactory{
    DatingApp* createApp(){
        return new Hinge();
    }
};
void printGirlsList(MobileAppFactory* factory){
    factory->getApp()->getGirls();
}
int main(){
    MobileAppFactory* factory1=new TinderMobileAppFactory();
    MobileAppFactory* factory2=new HingeMobileAppFactory();
    printGirlsList(factory1);
    printGirlsList(factory2);

    return 0;
}