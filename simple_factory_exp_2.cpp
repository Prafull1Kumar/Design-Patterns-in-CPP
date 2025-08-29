#include<iostream>
using namespace std;
class Vehicle{
    public:
    virtual void bookingDetails()=0;
};
class Bike:public Vehicle{
    public:
    void bookingDetails(){
        cout<<"Your Bike will be arriving soon"<<"\n";
    }
};
class Car:public Vehicle{
    public:
    void bookingDetails(){
        cout<<"Your Car will be arriving soon"<<"\n";
    }
};
class TravellerBus:public Vehicle{
    public:
    void bookingDetails(){
        cout<<"Your Traveller Bus will be arriving soon"<<"\n";
    }
};
class Notvalid:public Vehicle{
    public:
    void bookingDetails(){
        cout<<"No vehicle exist with this much seats"<<"\n";
    }
};

// Here Ola is working as factory class 
// and all other as a concrete class
class Ola{
    public:
    Vehicle* assignVehicle(int seat){
        if(seat<=2){
            return new Bike();
        }
        else if(seat<=5){
            return new Car();
        }
        else if(seat<=17){
            return new TravellerBus();
        }
        // else{
        //     cout<<"Vehicle with "<<seat<<" number of seat is not available"<<"\n";
            return new Notvalid();
        // }
    }
};
int main(){
    Ola* o1=new Ola();
    Vehicle* v1;
    v1=o1->assignVehicle(7);
    v1->bookingDetails(9);
    return 0;
}