#include<iostream>
#include<vector>
using namespace std;
class Document{
    public:
    virtual Document* clone()=0;
    virtual void store()=0;
};
class xmlDocument:public Document{
    public:
    Document* clone(){
        return new xmlDocument();
    }
    void store(){
        cout<<"document.xml"<<"\n";
        return ;
    }
};
class PlainTextDocument:public Document{
    public:
    Document* clone(){
        return new PlainTextDocument();
    }
    void store(){
        cout<<"document.txt"<<"\n";
        return ;
    }
};
class SpreadSheetDocument:public Document{
    public:
    Document* clone(){
        return new SpreadSheetDocument();
    }
    void store(){
        cout<<"document.csv"<<"\n";
        return ;
    }
};
class DocumentManager{
    vector<Document*> docs={new xmlDocument(),new PlainTextDocument(),new SpreadSheetDocument()};
    public:
    Document* makeDocument(int choice){
        return docs[choice]->clone();
    }
};
int main(){
    vector<Document*> docs;
    DocumentManager* documentmanager=new DocumentManager();
    while(true){
    // for(int i=2;i>=-1;i--){    
        cout<<"xml(0) Plain(1) SpreadSheet(2) :- ";
        int n=rand()%4;
        cout<<n<<"\n";
        // int n=i;
        // cin>>n;
        if(n<0 || n>=3){
            break;
        }
        docs.push_back(documentmanager->makeDocument(n));
    }
    for(int i=0;i<docs.size();i++){
        docs[i]->store();
    }
    return 0;
}