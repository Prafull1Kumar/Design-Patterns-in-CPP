#include <iostream>
#include <vector>
#include <algorithm>

class Observer {
public:
    virtual void update(int value) = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;
    int state;
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() {
        for (auto observer : observers) {
            observer->update(state);
        }
    }

    void setState(int value) {
        state = value;
        notify();
    }
};

class ConcreteObserver : public Observer {
private:
    int observerState;
public:
    void update(int value) override {
        observerState = value;
        std::cout << "Observer updated with new state: " << observerState << std::endl;
    }
};

int main() {
    Subject subject;
    ConcreteObserver observer1, observer2;

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.setState(5);
    subject.setState(10);

    subject.detach(&observer1);
    subject.setState(15);

    return 0;
}
