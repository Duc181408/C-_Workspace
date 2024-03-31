#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
public:
    // attributes
    string name;
    int health;
    int xp;
    // methods
    void talk(string);
    bool is_dead1();
};

class Account {
public:
    // attributes
    string name;
    double balance;

    // methods
    void deposit(double bal){balance+=bal; cout<<"in deposit"<<endl;};
    void withdraw(double bal){balance-=bal; cout<<"in withdraw"<<endl;};
};


int main()
{
    Account frank_account;
    frank_account.name = "Frank's Account";
    frank_account.balance = 5000.0;
    
    frank_account.deposit(500.0);
    frank_account.withdraw(500.0);



    Player frank;
    frank.name = "Frank";
    frank.health  = 100;
    frank.xp = 12;

     Player *enemy{nullptr};
    enemy = new Player;
    // enemy->talk("Dume no vao ham nay");

    cout << "Helloo" << endl;
    return 0;
}

