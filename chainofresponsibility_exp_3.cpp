#include<iostream>
using namespace std; 
/*
When to use Chain of Responsibility Pattern?
When you want to decouple the sending request with the object being assign to handle
that request
*/

class BodyType{
    BodyType *next;
    public:
    string Diet;
    string type;
    void setNext(BodyType* next){
        this->next=next;
    }
    void getBodyType(int protien){
        if(protien<=50){
            cout<<type<<" Body Type is assigned to given protein intake"<<"\n";
            cout<<"Diet Plan: "<<Diet<<"\n";
            return ;
        }
        else{
            if(next!=nullptr){
                next->getBodyType(protien-50);
            }
            else{
                cout<<"To high Protien Intake"<<"\n";
            }
        }
    }
};
class Bulking:public BodyType{
    public:
    Bulking(string Diet, string type){
        this->Diet=Diet;
        this->type=type;
    }
};
class Cutting:public BodyType{
    public:
    Cutting(string Diet, string type){
        this->Diet=Diet;
        this->type=type;
    }
};
class LeanBody: public BodyType{
    public:
    LeanBody(string Diet, string type){
        this->Diet=Diet;
        this->type=type;
    }
};
class NormalDiet:public BodyType{
    public:
    NormalDiet(string Diet,string type){
        this->Diet=Diet;
        this->type=type;
    }
};
class ChainOfResponsibility{
    public:
    ChainOfResponsibility(){}
    BodyType* getIntialBodyType(){
        BodyType* bulking=new Bulking("High Carb Diet","Bulking");
        BodyType* cutting=new Cutting("Cutting Diet","Cutting");
        BodyType* leanBody=new LeanBody("Lean Body Diet","Lean Body");
        BodyType* normalDiet=new NormalDiet("Normal Diet","Normal Diet");
        normalDiet->setNext(leanBody);
        leanBody->setNext(cutting);
        cutting->setNext(bulking);
        return normalDiet;
    }
};
int main(){
    ChainOfResponsibility* cor=new ChainOfResponsibility();
    BodyType* bt=cor->getIntialBodyType();
    bt->getBodyType(120);
    bt->getBodyType(30);
    return 0;
}