#include<iostream>
using namespace std;
/*
class Window 
{
public:
  virtual void draw() = 0;
  virtual string getDescription() = 0;
  virtual ~Window() {}
};
 
class SimpleWindow : public Window 
{
public:
  void draw() {
    // draw window 
  }
  string getDescription() {
	  return "simple window\n";
  }
};

class WindowDecorator : public Window 
{
protected:
	Window *m_decoratedWindow; 
 
public:
	WindowDecorator (Window *decoratedWindow): 
	  m_decoratedWindow(decoratedWindow) {}
};

class VerticalScrollBarDecorator : public WindowDecorator 
{
public:
	VerticalScrollBarDecorator (Window *decoratedWindow): 
		WindowDecorator(decoratedWindow) {}
 
	void draw() {
        drawVerticalScrollBar();
        m_decoratedWindow->draw();
    }
 
    string getDescription() {
        return m_decoratedWindow->getDescription() + "with vertical scrollbars\n";
    }

private:
	void drawVerticalScrollBar() {
        // draw the vertical scrollbar
    }
};

class HorizontalScrollBarDecorator : public WindowDecorator 
{
public:
	HorizontalScrollBarDecorator (Window *decoratedWindow): 
		WindowDecorator(decoratedWindow) {}
 
	void draw() {
        drawHorizontalScrollBar();
        m_decoratedWindow->draw();
    }
 
    string getDescription() {
        return m_decoratedWindow->getDescription() + "with horizontal scrollbars\n";
	}
private:
	void drawHorizontalScrollBar() {
        // draw the horizontal scrollbar
    }
};

int main()
{
  Window *simple = new SimpleWindow();
  cout << simple -> getDescription() << endl;

  Window *horiz = new HorizontalScrollBarDecorator (simple);
  cout << horiz -> getDescription() << endl;

  Window *vert = new VerticalScrollBarDecorator ( new SimpleWindow());
  cout << vert -> getDescription() << endl;

  Window *decoratedWindow = new HorizontalScrollBarDecorator (
                new VerticalScrollBarDecorator(new SimpleWindow()));
  cout << decoratedWindow -> getDescription() << endl;

  return 0;
}*/

class Beverage{
    public:
    string beverageName="";
    virtual string getBeverageName()=0;
    // string getBeverageName(){
    //     return this->beverageName;
    // }
    virtual int getPrice()=0;
};
class Espresso:public Beverage{
    public:
    Espresso(){
        this->beverageName="Espresso";
    }
    string getBeverageName(){
        return this->beverageName;
    }
    int getPrice(){
        return 45;
    }
};
class Cappuccino:public Beverage{
    public:
    Cappuccino(){
        this->beverageName="Cappuccino";
    }
    string getBeverageName(){
        return this->beverageName;
    }
    int getPrice(){
        return 60;
    }
};
class addOn:public Beverage{
    public:
    Beverage* beverage;
    addOn(Beverage* b):beverage(b){}
    // virtual string getBeverageName()=0;
};
class Milk:public addOn{
    public:
    Milk(Beverage* b):addOn(b){}
    string getBeverageName(){
        return beverage->getBeverageName()+" with milk";
    }
    int getPrice(){
        return beverage->getPrice()+25;
    }
};
class Caremel:public addOn{
    public:
    Caremel(Beverage* b):addOn(b){}
    string getBeverageName(){
        return beverage->getBeverageName()+" with Caremel";
    }
    int getPrice(){
        return beverage->getPrice()+30;
    }
};
int main(){
    Beverage* exp=new Espresso();
    cout<<exp->getBeverageName()<<"\n";
    cout<<exp->getPrice()<<"\n";
    exp=new Milk(exp);
    cout<<exp->getBeverageName()<<"\n";
    cout<<exp->getPrice()<<"\n";
    exp=new Milk(exp);
    cout<<exp->getBeverageName()<<"\n";
    cout<<exp->getPrice()<<"\n";
    Beverage* cap=new Cappuccino();
    cap=new Caremel(cap);
    cap=new Caremel(cap);
    cout<<cap->getBeverageName()<<"\n";
    cout<<cap->getPrice()<<"\n";
    return 0;
}



