// Pizza ordering app

#include<bits/stdc++.h>
using namespace std;
class Pizza{
    public:
    string name;
    virtual string getPizza()=0;
    virtual int getPrice()=0;
};
class Margherita:public Pizza{
    public:
    Margherita(){
        this->name="Margherita";
    }
    string getPizza(){
        return this->name;
    }
    int getPrice(){
        return 120;
    }
};
class Farmhouse:public Pizza{
    public:
    Farmhouse(){
        this->name="FarmHouse";
    }
    string getPizza(){
        return this->name;
    }
    int getPrice(){
        return 210;
    }
};
class Topping:public Pizza{
    public:
    Pizza* pizza;
    Topping(Pizza* p):pizza(p){}
};
class Paneer:public Topping{
    public:
    Paneer(Pizza* p):Topping(p){}
    string getPizza(){
        return pizza->getPizza()+" with Paneer";
    }
    int getPrice(){
        return pizza->getPrice()+60;
    }
};
class Onion:public Topping{
    public:
    Onion(Pizza* p):Topping(p){}
    string getPizza(){
        return pizza->getPizza()+" with Onion";
    }
    int getPrice(){
        return pizza->getPrice()+30;
    }
};
int main(){
    Pizza* p1=new Margherita();
    cout<<p1->getPizza()<<"\n";
    cout<<p1->getPrice()<<"\n";
    p1=new Onion(p1);
    cout<<p1->getPizza()<<"\n";
    cout<<p1->getPrice()<<"\n";
    p1=new Paneer(p1);
    cout<<p1->getPizza()<<"\n";
    cout<<p1->getPrice()<<"\n";
    return 0;
}