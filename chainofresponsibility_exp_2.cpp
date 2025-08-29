#include<iostream>
using namespace std;
class WithDrawCash{
    public:
    WithDrawCash* withdrawcash;
    int note;
    void processingCashWithDrawl(int amount){

        if(amount%100){
            cout<<"Please Enter amount in multiple of 100"<<"\n";
            return ;
        }

        if(amount/(this->note)>0){
            cout<<"You get "<<(amount/this->note)<<" number of "<<this->note<<" notes"<<"\n";
        }
        amount=(amount%(this->note));
        if(withdrawcash!=nullptr){
            withdrawcash->processingCashWithDrawl(amount);
        }
        return ;
    }
    void setLowerCash(WithDrawCash* w){
        this->withdrawcash=w;
    }
};
class WithDraw2000Cash:public WithDrawCash{
    public:
    WithDraw2000Cash(int n){
        this->note=n;
    }
};
class WithDraw500Cash:public WithDrawCash{
    public:
    WithDraw500Cash(int n){
        this->note=n;
    }
};
class WithDraw100Cash:public WithDrawCash{
    public:
    WithDraw100Cash(int n){
        this->note=n;
    }
};
class ATM{
    public:
    ATM(){};
    
    WithDrawCash* ATMCashWithDrawer(){
        WithDrawCash* hundred=new WithDraw100Cash(100);
        WithDrawCash* fivehundred=new WithDraw500Cash(500);
        WithDrawCash* twothousand=new WithDraw2000Cash(2000);
        twothousand->setLowerCash(fivehundred);
        fivehundred->setLowerCash(hundred);
        hundred->setLowerCash(nullptr);
        return twothousand;
    }
};
int main(){
    ATM* atm=new ATM();
    WithDrawCash* w=atm->ATMCashWithDrawer();
    w->processingCashWithDrawl(345000);
    cout<<"Next Transaction"<<"\n";
    w->processingCashWithDrawl(5000);
    cout<<"Next Transaction"<<"\n";
    w->processingCashWithDrawl(4600);
    cout<<"Next Transaction"<<"\n";
    w->processingCashWithDrawl(500);
    cout<<"Next Transaction"<<"\n";
    w->processingCashWithDrawl(22410);
    return 0;
}