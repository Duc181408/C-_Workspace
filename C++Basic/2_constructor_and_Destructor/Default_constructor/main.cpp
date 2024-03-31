#include <iostream>

using namespace std;

class Account {
private:
    string name;
    double balance;
public:
    Account(string name_val, double bal){
        name = name_val;
        balance = bal;
    }
    void deposit(double bal){balance+=bal; cout<<"in deposit"<<endl;};
    void withdraw(double bal){balance-=bal; cout<<"in withdraw"<<endl;};
};

int main()
{
    Account bill_account{"Bill", 10000.0};
    Account Duc_acc = Account("Duc_acc", 1000.0);
    return 0;
}