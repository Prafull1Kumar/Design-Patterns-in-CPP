#include<iostream>
#include<map>
#include<functional>
using namespace std;
// https://www.youtube.com/watch?v=QNpwWkdFvgQ&t=13s
class Car{
    public:
    virtual void yourCar()=0;
};
class Mahindra:public Car{
    public:
    void yourCar(){
        cout<<"Congratulation you brought a Mahindra SUV"<<"\n";
    }
};
class Tata:public Car{
    public:
    void yourCar(){
        cout<<"Congratulation you brought a TATA punch"<<"\n";
    }
};
class BMW:public Car{
    public:
    void yourCar(){
        cout<<"Congratulation you brought a BMW Series 5"<<"\n";
    }
};
class Audi:public Car{
    public:
    void yourCar(){
        cout<<"Congratulation you brought a Audi A5"<<"\n";
    }
};
class NoCar:public Car{
    public:
    void yourCar(){
        cout<<"This Car Stock is empty"<<"\n";
    }
};
// Abstract Factory with registration
class Factory {
public:
    using CarCreator = std::function<Car*()>;
    virtual Car* buy(const string& name) {
        auto it = creators.find(name);
        if (it != creators.end()) {
            return it->second();
        }
        return new NoCar();
    }
    void registerCar(const string& name, CarCreator creator) {
        creators[name] = creator;
    }
protected:
    std::map<string, CarCreator> creators;
};

class IndiaFactory : public Factory {
public:
    IndiaFactory() {
        registerCar("Tata", []() { return new Tata(); });
        registerCar("Mahindra", []() { return new Mahindra(); });
    }
};

class USFactory : public Factory {
public:
    USFactory() {
        registerCar("Audi", []() { return new Audi(); });
        registerCar("BMW", []() { return new BMW(); });
    }
};

class AssignFactory {
public:
    using FactoryCreator = std::function<Factory*()>;
    AssignFactory() {
        registerFactory("India", []() { return new IndiaFactory(); });
        registerFactory("USA", []() { return new USFactory(); });
    }
    Factory* findFactory(const string& location) {
        auto it = factories.find(location);
        if (it != factories.end()) {
            return it->second();
        }
        cout << "No Factory at this location" << "\n";
        return nullptr;
    }
    void registerFactory(const string& location, FactoryCreator creator) {
        factories[location] = creator;
    }
private:
    std::map<string, FactoryCreator> factories;
};
int main() {
    AssignFactory assign;
    Factory* f1 = assign.findFactory("USA");
    if (f1) {
        Car* c1 = f1->buy("Audi");
        c1->yourCar();
        delete c1;
        Car* c2 = f1->buy("BMW");
        c2->yourCar();
        delete c2;
        Car* c3 = f1->buy("K");
        c3->yourCar();
        delete c3;
        delete f1;
    }
    Factory* f2 = assign.findFactory("India");
    if (f2) {
        Car* c4 = f2->buy("Mahindra");
        c4->yourCar();
        delete c4;
        delete f2;
    }
    Factory* f3 = assign.findFactory("Pakistan");
    // f3->buy("")
    if (f3) delete f3;
    return 0;
}