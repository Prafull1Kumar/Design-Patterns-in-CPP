#include<iostream>
using namespace std;
class GameUnit{
    int x;
    int y;
    GameUnit(){
        x=0,y=0;
    }
    void initialize(){
        return new GameUnit(0,0);
    }
    virtual GameUnit* clone()=0;
};
class Swordman:public GameUnit{
    string attack;

    Swordman* clone(){
        attack="Knife";
        initialize();
    }
};
int main(){
    
    return 0;
}