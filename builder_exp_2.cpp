#include<iostream>
using namespace std;
// address
class Address{ 
    public:
    virtual void getAddress()=0;
    virtual void setPlotNo(string no)=0;
    virtual void setStreet(string street)=0;
    virtual void setPincode(string code)=0;
    virtual void setCity(string city)=0;
    virtual void setState(string state)=0;
};
class IndianTemplate:public Address{
    public:
    string plot_no;
    string street;
    string pincode;
    string city;
    string state;
    // IndianTemplate(){}
    void setPlotNo(string no){
        this->plot_no=no;
    }
    void setStreet(string street){
        this->street=street;
    }
    void setPincode(string code){
        this->pincode=code;
    }
    void setCity(string city){
        this->city=city;
    }
    void setState(string state){
        this->state=state;
    }
    void getAddress(){
        cout<<"Plot no. : "<<this->plot_no<<", "<<this->street<<","<<"\n";
        cout<<this->city<<", "<<this->state<<","<<"\n";
        cout<<"Pincode: "<<this->pincode<<"\n";
    }
};
class USTemplate:public Address{
    public:
    string plot_no;
    string street;
    string pincode;
    string city;
    string state;
    // IndianTemplate(){}
    void setPlotNo(string no){
        this->plot_no=no;
    }
    void setStreet(string street){
        this->street=street;
    }
    void setPincode(string code){
        this->pincode=code;
    }
    void setCity(string city){
        this->city=city;
    }
    void setState(string state){
        this->state=state;
    }
    void getAddress(){
        cout<<this->street<<","<<"\n";
        cout<<this->city<<", "<<this->state<<"\n";
        cout<<"Pincode: "<<this->pincode<<"\n";
    }
};
class Builder{
    public:
    virtual Builder* setBuilderPlotNo(string)=0;
    virtual Builder* setBuilderStreet(string)=0;
    virtual Builder* setBuilderPincode(string)=0;
    virtual Builder* setBuilderCity(string)=0;
    virtual Builder* setBuilderState(string)=0;
    virtual Address* build()=0;
};    
class ConcreteBuilder:public Builder{
    Address* address;
    public:
    ConcreteBuilder(Address* ad):address(ad){}
    Builder* setBuilderPlotNo(string no){
        address->setPlotNo(no);
        return this;
    }
    Builder* setBuilderStreet(string strt){
        address->setStreet(strt);
        return this;
    }
    Builder* setBuilderPincode(string code){
        address->setPincode(code);
        return this;
    }
    Builder* setBuilderCity(string city){
        address->setCity(city);
        return this;
    }
    Builder* setBuilderState(string state){
        address->setState(state);
        return this;
    }
    Address* build(){
        return address;
    }
};

int main(){
    
    Builder* build=new ConcreteBuilder(new IndianTemplate());
    cout<<"Indian Template"<<"\n";
    Address* address=build->setBuilderCity("Nagpur")->setBuilderPincode("440027")
    ->setBuilderPlotNo("34")->setBuilderState("Maharashtra")->setBuilderStreet("Chandra Nagar Lan No. 2")->build();
    address->getAddress();
    cout<<"\n";
    cout<<"US Template"<<"\n";
    build=new ConcreteBuilder(new USTemplate());
    address=build->setBuilderCity("Los angeles")->setBuilderPincode("90005")
    ->setBuilderState("California")->setBuilderStreet("Hollywood Boulevard")->build();
    address->getAddress();
    return 0;
}

/*
string getPlotNo(){
        return this->plot_no;
    }
    string getStreet(){
        return this->street;
    }
    string getPincode(){
        return this->pincode;
    }
    string getCity(){
        return this->city;
    }
    string getState(){
        return this->state;
    }
*/