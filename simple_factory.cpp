#include<iostream>
using namespace std;
class DataSource{
    public:
    virtual void connect()=0; 
};
class Postgres:public DataSource{
    public:
    void connect(){
        cout<<"Postgres DataSource is connected"<<"\n";
    }
};
class MongoDB:public DataSource{
    public:
    void connect(){
        cout<<"MongoDB Datasource is connected"<<"\n";
    }
};
class MySql:public DataSource{
    public:
    void connect(){
        cout<<"MySql DataSource is connected"<<"\n";
    }
};
class FactoryService{
    DataSource* datasource;
    public:
    DataSource* getDataSource(string name){
        if(name=="Postgres"){
            datasource=new Postgres();
        }
        else if(name=="MySql"){
            datasource=new MySql();
        }
        else if(name=="MongoDB"){
            datasource=new MongoDB();
        }
        return datasource;
    }
};
class DataSourceService{
    FactoryService* factory;
    public:
    DataSourceService(FactoryService* f){
        this->factory=f;
    }
    void connectToDataSource(string name){
        factory=new FactoryService();
        DataSource* db=factory->getDataSource(name);
        db->connect();
    }
};
int main(){
    FactoryService* factory=new FactoryService();
    DataSourceService* service=new DataSourceService(factory);
    service->connectToDataSource("Postgres");
    service->connectToDataSource("MySql");
    service->connectToDataSource("MongoDB");
    return 0;
}