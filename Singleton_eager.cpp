#include<iostream>
using namespace std;

// Eager singleton: instance is created when the class is loaded
class Wifi {
    string password;
    static Wifi* wifi;

    // private ctor to prevent external construction
    Wifi(string pwd) : password(pwd) {}

public:
    static Wifi* getInstance() {
        return wifi;
    }

    string getPassword() {
        return password;
    }

    void setPassword(const string& pwd) {
        password = pwd;
    }
};

Wifi* Wifi::wifi = new Wifi("password");

int main() {
    Wifi* c1 = Wifi::getInstance();
    Wifi* c2 = Wifi::getInstance();

    cout << "Print Default password of C1,C2 user" << "\n";
    cout << c1->getPassword() << "\n";
    cout << c2->getPassword() << "\n";

    cout << "c1 user update password" << "\n";
    c1->setPassword("123Passwordc1");

    cout << "Print updated password of C1,C2 user" << "\n";
    cout << c1->getPassword() << "\n";
    cout << c2->getPassword() << "\n";
    return 0;
}
