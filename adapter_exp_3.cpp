#include<iostream>

using namespace std;

class Customer{
    string name;
    string designation;
    string address;
    public:
    void setName(string name){
        this->name=name;
    }
    void setDesignation(string designation){
        this->designation=designation;
    }
    void setAddress(string address){
        this->address=address;
    }
    virtual string getName(){
        return this->name;
    }
    virtual string getAddress(){
        return this->address;
    }
    virtual string getDesignation(){
        return this->designation;
    }
};
class Employee{
    string fullName;
    string jobTitle;
    string officeLocation;
    public:
    void setFullName(string name){
        this->fullName=name;
    }
    void setJobTitle(string designation){
        this->jobTitle=designation;
    }
    void setOfficeLocation(string address){
        this->officeLocation=address;
    }
    string getFullName(){
        return this->fullName;
    }
    string getOfficeLocation(){
        return this->officeLocation;
    }
    string getJobTitle(){
        return this->jobTitle;
    }

};
class EmployeeObjectAdapter:public Customer{
    Employee* employee;
    public:
    EmployeeObjectAdapter(Employee* emp){
        this->employee=emp;
    }
    string getName(){
        return this->employee->getFullName();
    }
    string getAddress(){
        return this->employee->getOfficeLocation();
    }
    string getDesignation(){
        return this->employee->getJobTitle();
    }
};
class BussinessCard{
    string card;
    public:
    void designCard(Customer* cus){
        cout<<"Name: "<<cus->getName()<<"\n";
        cout<<"Designation: "<<cus->getDesignation()<<"\n";
        cout<<"Address: "<<cus->getAddress()<<"\n";
        return ; 
    }

};

int main(){
    Employee* emp1=new Employee();
    emp1->setFullName("Prafull");
    emp1->setJobTitle("Backend Developer");
    emp1->setOfficeLocation("Plot: 34, Bhagawan Nagar near Chandra Nagar Lan no 2");
    Customer* empadap=new EmployeeObjectAdapter(emp1);
    BussinessCard* card=new BussinessCard();
    card->designCard(empadap);
    Customer* cus=new Customer();
    cout<<"*******"<<"\n";
    cus->setAddress("Hyderabad, Jublee Hills");
    cus->setDesignation("CEO");
    cus->setName("Karthik");
    card->designCard(cus);
    return 0;
}