#include<iostream>
using namespace std;
class Storage{
    public:
    virtual string getId()=0;
    virtual string getName()=0;
};
class S3Storage:public Storage{
    public:
    S3Storage(string size){
        cout<<"S3 storage is created of size "<<size<<"\n";
    }
    string getId(){
        return "S31";
    }
    string getName(){
        return "S3 storage";
    }
};
class GoogleCloudStorage:public Storage{
    public:
    GoogleCloudStorage(string size){
        cout<<"Google storage is created of size "<<size<<"\n";
    }
    string getId(){
        return "GCS1";
    }
    string getName(){
        return "Google Cloud storage";
    }
}; 
class Instance{
    public:
    virtual void start()=0;
    virtual void stop()=0;
    virtual void attackStorage(Storage*)=0;
};
class EC2Instance:public Instance{
    public:
    EC2Instance(string size){
        cout<<"EC2 instance is create of size "<<size<<"\n";
    }
    void start(){
        cout<<"EC2 Instane is start"<<"\n";
    }
    void stop(){
        cout<<"EC2 instance is stop"<<"\n";
    }
    void attackStorage(Storage* storage){
        cout<<"EC2 instance is attached to "<<storage->getName()<<"\n";
    }
};
class GoogleComputingInstance:public Instance{
    public:
    GoogleComputingInstance(string size){
        cout<<"Google Computing instance is create of size "<<size<<"\n";
    }
    void start(){
        cout<<"Google Computing Instane is start"<<"\n";
    }
    void stop(){
        cout<<"Google Computing instance is stop"<<"\n";
    }
    void attackStorage(Storage* storage){
        cout<<"Google Computing instance is attached to "<<storage->getName()<<"\n";
    }
};
class ResourceFactory{
    public:
    virtual Instance* createInstance(string)=0;
    virtual Storage* createStorage(string)=0;
};

class AWSResourceFactory:public ResourceFactory{
    public:
    Instance* createInstance(string size){
        Instance* ec2=new EC2Instance(size);
        return ec2;
    }
    Storage* createStorage(string size){
        return new S3Storage(size);
    }
};
class GoogleResourceFactory:public ResourceFactory{
    public:
    Instance* createInstance(string size){
        return new GoogleComputingInstance(size);
        
    }
    Storage* createStorage(string size){
        return new GoogleCloudStorage(size);
    }
};
class Client{
    ResourceFactory* factory;
    public:
    Client(ResourceFactory* factory){
        this->factory=factory;
    }
    Instance* createServer(string instanceSize,string storageSize){
        Instance* instance=factory->createInstance(instanceSize);
        Storage* storage=factory->createStorage(storageSize);
        instance->attackStorage(storage);
        return instance;
    }
};
int main(){
    Client* client=new Client(new AWSResourceFactory());
    Instance* i1=client->createServer("Medium.2.x","2048 MB");
    i1->start();
    i1->stop();
    return 0;
}