#include<iostream>
using namespace std;
class Person{
    string first_name;
    string middle_name;
    string last_name;
    int age;
    int height;
    int weight;
    string father_name;
    string mother_name;
    public:
    Person(){
        first_name="";
        middle_name="";
        last_name="";
        age=0;
        height=0;
        weight=0;
        father_name="";
        mother_name="";
    }
    void setAge(int age){
        this->age=age;
    }
    void setHeight(int h){
        this->height=h;
    }
    void setWeight(int w){
        this->weight=w;
    }
    void setFirstName(string name){
        this->first_name=name;
    }
    void setMiddleName(string name){
        this->middle_name=name;
    }
    void setLastName(string name){
        this->last_name=name;
    }
    void setFatherName(string name){
        this->father_name=name;
    }
    void setMotherName(string name){
        this->mother_name=name;
    }
    void show(){
        cout<<"First Name:- "<<first_name<<"\n";
        cout<<"Middle Name:- "<<middle_name<<"\n";
        cout<<"Last Name:- "<<last_name<<"\n";
        cout<<"Age:- "<<age<<"\n";
        cout<<"Height:- "<<height<<"\n";
        cout<<"Weight:- "<<weight<<"\n";
        cout<<"Father Name:- "<<father_name<<"\n";
        cout<<"Mother Name:- "<<mother_name<<"\n";
    }
};
class Builder{
    Person person;
    public:
    Builder():person(){
    }
    Builder* setAge(int age){
        person.setAge(age);
        return this;
    }
    Builder* setHeight(int h){
        person.setHeight(h);
        return this;
    }
    Builder* setWeight(int w){
        person.setWeight(w);
        return this;
    }
    Builder* setFirstName(string name){
        person.setFirstName(name);
        return this;
    }
    Builder* setMiddleName(string name){
        person.setMiddleName(name);
        return this;
    }
    Builder* setLastName(string name){
        person.setLastName(name);
        return this;
    }
    Builder* setFatherName(string name){
        person.setFatherName(name);
        return this;
    }
    Builder* setMotherName(string name){
        person.setMotherName(name);
        return this;
    }
    void showInfo(){
        person.show();
    }
};
int main(){
    Builder* B1=new Builder();
    B1->setFirstName("Prafull")->setAge(23)->setLastName("Kumar")->setHeight(173);
    B1->showInfo();
    return 0;
}