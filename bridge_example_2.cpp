#include<iostream>
#include<string>
using namespace std;
class MoveLogic
{
public:
    virtual void move() = 0;
};
class Drivecar : public MoveLogic
{
public:
    void move()
    {
        cout << "Go to office\n";
    }
};
class Stayatcradle : public MoveLogic
{
public:
    void move()
    {
        cout << "Crawl\n";
    }
};
class Family
{
public:
    virtual void howDoIMove() = 0;
};
class Father : public Family
{
    MoveLogic* _myMoveLogic;
public:
    Father(MoveLogic *obj) :_myMoveLogic(obj){}
    void howDoIMove()
    {
        _myMoveLogic->move();
    }
};
class Toddler : public Family
{
    MoveLogic* _myMoveLogic;
public:
    Toddler(MoveLogic *obj) :_myMoveLogic(obj){}
    void howDoIMove()
    {
        _myMoveLogic->move();
    }
};
int main()
{
    MoveLogic* drivecar = new Drivecar();
    MoveLogic* stayatcradle  = new Stayatcradle();
    Family* FamilyA = new Father(drivecar);
    Family* FamilyB = new Toddler(stayatcradle);
    FamilyA->howDoIMove();
    FamilyB->howDoIMove();
    return 1;
}