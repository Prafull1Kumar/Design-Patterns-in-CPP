#include<iostream>
using namespace std;
class Car{
    public:
    virtual void yourCar()=0;
};
class Mahindra:public Car{
    public:
    void yourCar(){
        cout<<"Congratulation you brought a Mahindra SUV"<<"\n";
    }
};
class Tata:public Car{
    public:
    void yourCar(){
        cout<<"Congratulation you brought a TATA punch"<<"\n";
    }
};
class BMW:public Car{
    public:
    void yourCar(){
        cout<<"Congratulation you brought a BMW Series 5"<<"\n";
    }
};
class Audi:public Car{
    public:
    void yourCar(){
        cout<<"Congratulation you brought a Audi A5"<<"\n";
    }
};
class NoCar:public Car{
    public:
    void yourCar(){
        cout<<"This Car Stock is empty"<<"\n";
    }
};
class Factory{
    public:
    virtual Car* buy(string location)=0;
};
class IndiaFactory:public Factory{
    public:
    Car* buy(string name){
        if(name=="Tata"){
            return new Tata();
        }
        else if(name=="Mahindra"){
            return new Mahindra();
        }
        return new NoCar();
    }
};
class USFactory:public Factory{
    public:
    Car* buy(string name){
        if(name=="Audi"){
            return new Audi();
        }
        else if(name=="BMW"){
            return new BMW();
        }
        return new NoCar();
    }
};
class defaultFactory:public Factory{
    public:
    Car* buy(string name){
        // if(name=="Audi"){
        //     return new Audi();
        // }
        // else if(name=="BMW"){
        //     return new BMW();
        // }
        cout<<"No Factory at this location"<<"\n";
        return NULL;
    }
};
class AssignFactory{
    public:
    Factory* findFactory(string location){
        if(location=="India"){
            return new IndiaFactory();
        }
        else if(location=="USA"){
            return new USFactory();
        }
        cout<<"No Factory at this location"<<"\n";
        return NULL;
    }
};
int main(){
    AssignFactory* assign;
    Factory* f1=assign->findFactory("USA");
    Car* c1=f1->buy("Audi");
    c1->yourCar();
    Car* c2=f1->buy("BMW");
    c2->yourCar();
    Car* c3=f1->buy("K");
    c3->yourCar();
    Factory* f2=assign->findFactory("India");
    Car* c4=f2->buy("Mahindra");
    c4->yourCar();
    Factory* f3=assign->findFactory("Pakistan");
    // f3->buy("")
    return 0;
}