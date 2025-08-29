#include<iostream>
using namespace std;
class nonVegMenu{
    public:
    void menu(){
        cout<<"non veg menu..."<<"\n";
        return ;
    }
};
class vegMenu{
    public:
    void menu(){
        cout<<"veg menu..."<<"\n";
        return ;
    }
};
// waiter is the facade which hides the 
// complexity of geting different menu
class Waiter{
    nonVegMenu* non_veg_menu;
    vegMenu* veg_menu;
    public:
    Waiter(){
        non_veg_menu=new nonVegMenu();
        veg_menu=new vegMenu();
    }
    
    void getNonVeg(){
        non_veg_menu->menu();
        return ;
    }
    void getVeg(){
        veg_menu->menu();
        return ;
    }
};
int main(){
    Waiter* w1=new Waiter();
    w1->getVeg();
    w1->getNonVeg();
    return 0;
}