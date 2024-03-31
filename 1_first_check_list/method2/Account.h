#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

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

#endif //_ACCOUNT_H_
