#include<iostream>
using namespace std;
/*
    Strategy Pattern
When to use Strategy Pattern?   
ans)
1. When you have multiple algorithms for a specific task and 
    want to switch between them dynamically
2. When you want to isolate the implementation details of an algorithm 
    from the code that uses it
*/
class Resolution{
    public:
    virtual void getResolution()=0;
};
class Resolution480:public Resolution{
    public:
    void getResolution(){
        cout<<"Resolution 480"<<"\n";
        return ;
    }
};
class Resolution1080:public Resolution{
    public:
    void getResolution(){
        cout<<"Resolution 1080"<<"\n";
        return;
    }
};
class Device{
    public:
    virtual void getDevice()=0;
};
class TV:public Device{
    public:
    void getDevice(){
        cout<<"This is TV with ";
        return ;
    }
};
class Phone:public Device{
    public:
    void getDevice(){
        cout<<"This is Phone with ";
        return ;
    }
};
class VideoPlayer{
    public:
    Device* device;
    Resolution* resolution;
    // VideoPlayer(Device* d,Resolution* r):device(d),resolution(r){}
    virtual void getVideoPlayer()=0;
};
class PhonePlayer:public VideoPlayer{
    public:
    PhonePlayer(Device* d,Resolution* r){
        this->device=d;
        this->resolution=r;
    }
    void getVideoPlayer(){
        device->getDevice();
        resolution->getResolution();
    }
};
class TVPlayer:public VideoPlayer{
    public:
    TVPlayer(Device* d,Resolution* r){
        this->device=d;
        this->resolution=r;
    }
    void getVideoPlayer(){
        device->getDevice();
        resolution->getResolution();
    }
};
int main(){
    Device* d1=new Phone();
    Device* d2=new TV();
    Resolution* r1=new Resolution480();
    Resolution* r2=new Resolution1080();
    VideoPlayer* v1=new PhonePlayer(d1,r1);
    // VideoPlayer* v3=new PhonePlayer(d2,r1);
    VideoPlayer* v2=new TVPlayer(d2,r2);
    v1->getVideoPlayer();
    v2->getVideoPlayer();

    return 0;
}