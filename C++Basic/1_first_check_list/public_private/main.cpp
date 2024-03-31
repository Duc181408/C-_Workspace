#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Account {
private:
    // attributes
    string name {"user"};
    double balance = 1000.0;
public:
    // methods
    void deposit(double bal){balance+=bal; cout<<"in deposit"<<endl;};
    void withdraw(double bal){balance-=bal; cout<<"in withdraw"<<endl;};
};


int main()
{
    Account frank;
    frank.deposit(5000.0);
    frank.withdraw(500.0);

    cout << "Helloo" << endl;
    return 0;
}

