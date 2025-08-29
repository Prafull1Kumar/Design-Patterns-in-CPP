#include<iostream>
#include<vector>
using namespace std;
class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int val){
        this->data=val;
        next=nullptr;
    }
};
class DataStructue{
    public:
    virtual void add(int)=0;
    virtual int front_pop()=0;
    virtual bool empty()=0;
};
class SinglyLinkList:public DataStructue{
    ListNode* head;
    ListNode* end;
    public:
    SinglyLinkList(){
        this->head=new ListNode(0);
        this->end=this->head;
    }
    void add(int val){
        end->next=new ListNode(val);
        end=end->next;
    }
    int front_pop(){
        int val=head->next->data;
        head=head->next;
        return val;
    }
    bool empty(){
        if(head->next==nullptr){
            return true;
        }
        return false;
    }
};
class Array :public DataStructue{
    vector<int> head;
    int n;
    int start;
    public:
    Array(){
        this->start=0;
        this->n=0;
    }
    void add(int val){
        head.push_back(val);
        n++;
    }
    int front_pop(){
        return head[start++];
    }
    bool empty(){
        if(start>=n){
            return true;
        }
        return false;
    }
};
class Queue{
    DataStructue* datastructure;
    public:
    Queue(DataStructue* datastru){
        this->datastructure=datastru;
    }
    void push(int val){
        datastructure->add(val);
    }
    int front(){
        return datastructure->front_pop();
    }
    bool empty(){
        return datastructure->empty();
    }
};
int main(){
    Queue* q=new Queue(new SinglyLinkList());
    q->push(1);
    q->push(2);
    q->push(4);
    q->push(3);
    while(!q->empty()){
        cout<<q->front()<<"\n";
    }
    cout<<"*************"<<"\n";
    Queue* q2=new Queue(new Array());
    q2->push(1);
    q2->push(2);
    q2->push(3);
    q2->push(4);
    while(!q2->empty()){
        cout<<q2->front()<<"\n";
    }
    return 0;
}