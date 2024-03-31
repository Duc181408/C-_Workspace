#include "Account.h"

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
