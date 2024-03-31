#include <iostream>
#include "Account.h"

using namespace std;

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

