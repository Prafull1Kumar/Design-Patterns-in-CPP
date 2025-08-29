#include<iostream>
using namespace std;
class HospitalMedicalClaim{
    public:
    string first_name;
    string last_name;
    int age;
    int totalcost;
    string disease;
    HospitalMedicalClaim(string first_name,string last_name,int age,int totalcost,string disease){
        this->first_name=first_name;
        this->last_name=last_name;
        this->age=age;
        this->totalcost=totalcost;
        this->disease=disease;
    }
};
// this is behaving as adaptor
class CompanyMedicalClaim{
    public:
    string full_name;
    int age;
    int refundClaim;
    string illness;
    CompanyMedicalClaim(string full_name,int age,int refundClaim,string illness){
        this->full_name=full_name;
        this->age=age;
        this->refundClaim=refundClaim;
        this->illness=illness;
    }
    CompanyMedicalClaim(HospitalMedicalClaim* claim){
        this->full_name=claim->first_name+" "+claim->last_name;
        this->age=claim->age;
        this->illness=claim->disease;
        this->refundClaim=claim->totalcost;
    }
};
class Refund{
    public:
    CompanyMedicalClaim* claim;
    Refund(CompanyMedicalClaim* claim){
        this->claim=claim;
    }
    void refundCost(){
        cout<<(claim->refundClaim-10)<<" will be refunded"<<"\n";
    }
};
int main(){
    HospitalMedicalClaim* h1=new HospitalMedicalClaim("Prafull","Prajapati",23,106000,"ACL Tier");
    CompanyMedicalClaim* c1=new CompanyMedicalClaim(h1);
    Refund* r1=new Refund(c1);
    r1->refundCost();
    return 0;
}