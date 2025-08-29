#include<iostream>
using namespace std;
class Manager{
    Manager* manager;
    public:
    int limit;
    string name;
    
    void setManager(Manager* m){
        this->manager=m;
    }
    void processRequest(int val){
        if(this->limit>=val){
            cout<<name<<" has accept your offer"<<"\n";
            return ;
        }
        else if(manager!=nullptr){
            cout<<"Request Process to "<<manager->name<<"\n";
            manager->processRequest(val);
            return ;
        }
        cout<<"Sorry we cannot negociate this amount"<<"\n";
        return ;
    }
};
class HiringManager:public Manager{
    public:
    HiringManager(string n,int l){
        this->name=n;
        this->limit=l;
    }
};
class SeniorManager:public Manager{
    public:
    SeniorManager(string n,int l){
        this->name=n;
        this->limit=l;
    }
};
class Director:public Manager{
    public:
    Director(string n,int l){
        this->name=n;
        this->limit=l;
    }
};
class ChainOfResponsibility{
    public:
    ChainOfResponsibility(){}
    Manager* getManager(){
        Director* d=new Director("Director",3000000);
        SeniorManager* sm=new SeniorManager("Senior Manager",2500000);
        HiringManager* hm=new HiringManager("Hiring Manager",1800000);
        d->setManager(nullptr);
        sm->setManager(d);
        hm->setManager(sm);
        return hm;
    }
};
int main(){
    ChainOfResponsibility* cor=new ChainOfResponsibility();
    Manager* m=cor->getManager();
    m->processRequest(300000);
    cout<<"\n";
    m->processRequest(1900000);
    cout<<"\n";
    m->processRequest(2600000);
    cout<<"\n";
    m->processRequest(3100000);
    return 0;
}