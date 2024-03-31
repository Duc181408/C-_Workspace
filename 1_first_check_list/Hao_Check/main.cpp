#include <iostream>
using namespace std;


class Account {
private:
    string name;
    double balance;
public:
    Account(){
        name = "None";
        balance = 0.0;
    }
    void deposit(double bal){balance+=bal; cout<<"in deposit"<<endl;};
    void withdraw(double bal){balance-=bal; cout<<"in withdraw"<<endl;};
};


class MyClass {
public:
    void function();
};
void MyClass::function()
{
        cout<<"Hello Hao"<<endl;
}

int main() {
    cout<<"Main ne "<<endl;
    MyClass myObject;
    myObject.function();
    return 0;
}
