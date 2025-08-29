#include<iostream>
using namespace std;
class Alcohol{
    public:
    string name;
    virtual string getDrinks()=0;
    virtual int getCost()=0;
};
class Vodka:public Alcohol{
    public:
    Vodka(){
        this->name="Vodha";
    }
    string getDrinks(){
        return name;
    }
    int getCost(){
        return 100;
    }
};
class Whisky:public Alcohol{
    public:
    Whisky(){
        this->name="Whisky";
    }
    string getDrinks(){
        return name;
    }
    int getCost(){
        return 140;
    }
};
class Rum: public Alcohol{
    public:
    Rum(){
        this->name="Rum";
    }
    string getDrinks(){
        return name;
    }
    int getCost(){
        return 200;
    }
};
class Beverage:public Alcohol{
    public:
    Alcohol* alcohol;
    virtual string getDrinks()=0;
    virtual int getCost()=0;
};
class Water:public Beverage{
    public:
    Water(Alcohol* alcohol){
        this->alcohol=alcohol;
    }
    string getDrinks(){
        return alcohol->getDrinks()+" with Water";
    }
    int getCost(){
        return alcohol->getCost()+10;
    }
};
class Coke:public Beverage{
    public:
    Coke(Alcohol* alcohol){
        this->alcohol=alcohol;
    }
    string getDrinks(){
        return alcohol->getDrinks()+" with coke";
    }
    int getCost(){
        return alcohol->getCost()+50;
    }
};
class Neat:public Beverage{
    public:
    Neat(Alcohol* alcohol){
        this->alcohol=alcohol;
    }
    string getDrinks(){
        return alcohol->getDrinks()+" with Neat";
    }
    int getCost(){
        return alcohol->getCost()+0;
    }
};
class Icecube:public Beverage{
    public:
    Icecube(Alcohol* alcohol){
        this->alcohol=alcohol;
    }
    string getDrinks(){
        return alcohol->getDrinks()+" on th rocks";
    }
    int getCost(){
        return alcohol->getCost()+30;
    }
};
int main(){
    Alcohol* alcohol=new Whisky();
    cout<<alcohol->getDrinks()<<"\n";
    cout<<alcohol->getCost()<<"\n";
    Beverage* beverage=new Water(alcohol);
    cout<<beverage->getDrinks()<<"\n";
    cout<<beverage->getCost()<<"\n";
    beverage=new Icecube(beverage);
    cout<<beverage->getDrinks()<<"\n";
    cout<<beverage->getCost()<<"\n";
    return 0;
}