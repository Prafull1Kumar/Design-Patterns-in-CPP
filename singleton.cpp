#include<iostream>
using namespace std;
class Singleton{
    int data;
    static Singleton* single;
    
    Singleton(int x){
        this->data=x;
    }
    public:
    Singleton* getInstance(){
        if(single==NULL){
            single=new Singleton(0);
        }
        return single;
    }
    int getData(){
        return this->data;
    }
    void setData(int x){
        this->data=x;
    }
};
Singleton *Singleton::single = 0;
int main(){
    Singleton* a;
    a=a->getInstance();
    // cout<<a->getData()<<"\n";
    a->setData(190);
    cout<<a->getData()<<"\n";
    Singleton* b;
    b=b->getInstance();
    // b->setData(101);
    cout<<b->getData()<<"\n";
    return 0;
}