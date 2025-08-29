#include<iostream>
using namespace std;
class Strategy{
    public:
    virtual int compute(int,int)=0;
};
class Add:public Strategy{
    int compute(int x,int y){
        return x+y;
    }
};
class Subtract:public Strategy{
    int compute(int x,int y){
        return x-y;
    }
};
class Multiply:public Strategy{
    int compute(int x,int y){
        return x*y;
    }
};
class Operation{
    Strategy* strategy;
    public:
    Operation(Strategy* s){
        this->strategy=s;
    }
    void result(int x,int y){
        cout<<strategy->compute(x,y)<<"\n";
    }
};
int main(){
    // Operation* op1=new Add();
    // cout<<op1->compute(2,4)<<"\n";
    // Operation* op2=new Subtract();
    // cout<<op2->compute(2,4)<<"\n";
    Operation* op=new Operation(new Add());
    op->result(4,5);
    op=new Operation(new Subtract());
    op->result(4,5);
    op=new Operation(new Multiply());
    op->result(4,5);
    return 0;
}