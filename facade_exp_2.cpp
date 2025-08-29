#include<iostream>
using namespace std;
class CPU{
    public:
    CPU(){}
    bool getCPU_ON(){
        cout<<"Your is CPU is ON"<<"\n";
        return true;
    }
};
class RAM{
    public:
    RAM(){}
    bool getRAM_ON(){
        cout<<"Your RAM is ON"<<"\n";
        return true;
    }
};
class Hardware{
    CPU* cpu;
    RAM* ram;
    public:
    Hardware(){
        this->cpu=new CPU();
        this->ram=new RAM();
    }
    bool getHardwareStarted(){
        if((this->cpu->getCPU_ON() && this->ram->getRAM_ON())){
            cout<<"Your hardware is working fine"<<"\n";
            return true;
        }
        return false;
    }
};
class OS{
    public:
    OS(){}
    bool getOS_ON(){
        cout<<"your OS is on"<<"\n";
        return true;
    }
};
class Driver{
    public:
    Driver(){}
    bool getDriverOn(){
        cout<<"Your Driver is on"<<"\n";
        return true;
    }
};
class Software{
    OS* os;
    Driver* driver;
    public:
    Software(){
        this->os=new OS();
        this->driver=new Driver();
    }
    bool getSoftware(){
        if(this->os->getOS_ON() && this->driver->getDriverOn()){
            cout<<"Your is software is working fine"<<"\n";
            return true;
        }
        return false;
    }
};
class System{
    Software* software;
    Hardware* hardware;
    public:
    System(){
        this->hardware=new Hardware();
        this->software=new Software;
    }
    bool getSytemOn(){
        if(software->getSoftware() && hardware->getHardwareStarted()){
            cout<<"Your System is started"<<"\n";
            return true;
        }
        return false;
    }
};
int main(){
    System* sys=new System();
    sys->getSytemOn();
    return 0;
}