#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Account {
private:
    // attributes
    string name;
    double balance;
public:
    // methods
    double get_balance(){return balance;};
    void set_balance(double bal)
    {
        balance = bal;
    }
    //implemented outside the class
    void set_name(string n);
    string getname();

    bool deposit(double amount);
    bool withdraw(double amount);
};

void Account::set_name(string n){
    name = n;
}

string Account::getname()
{
    return name;
}

bool Account::deposit(double amount)
{
    balance += amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if(get_balance()>= amount)
    {
        balance -= amount;
        return true;
    }
    else return false;
}

int main()
{
    Account frank_account;
    frank_account.set_name("frank_account");
    frank_account.set_balance(1000.0);
    if(frank_account.deposit(200.0))
    {
        cout<<"Deposit OK"<<endl;
    }
    else cout<<"Deposit not allowed"<<endl;
    if(frank_account.withdraw(500.0)) cout<<"Withdraw OK"<<endl;
    else cout<<"With draw is not successful"<<endl;
    cout << "Helloo" << endl;
    return 0;
}

