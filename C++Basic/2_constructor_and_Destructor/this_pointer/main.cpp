#include <iostream>

using namespace std;


class Account
{
private:
    string name;
    double balance;
public:
    
    Account(string name_val, double balance_val);
    ~Account();
};

Account::Account(string name_val, double balance_val)
:name{name_val},balance{balance_val}
{
}

Account::~Account()
{
    cout<< "Destructor is called for "+ name << endl;
}


int main()
{
    
    return 0;
}