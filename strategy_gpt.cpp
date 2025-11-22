#include <iostream>
using namespace std;
// Create Strategy Pattern
class Strategy {
public:
    virtual void execute() = 0;
};  
class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        cout << "Executing Strategy A" << "\n";
    }
};
class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        cout << "Executing Strategy B" << "\n";
    }
};

class Context {
private:
    Strategy* strategy;
public:
    Context(Strategy* strat) : strategy(strat) {}
    void setStrategy(Strategy* strat) {
        strategy = strat;
    }
    void executeStrategy() {
        strategy->execute();
    }
};  
int main() {
    Context* context = new Context(new ConcreteStrategyA());
    context->executeStrategy();  // Outputs: Executing Strategy A

    context->setStrategy(new ConcreteStrategyB());
    context->executeStrategy();  // Outputs: Executing Strategy B

    delete context;
    return 0;
}