#include <iostream>

using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;
public:
    string get_name() {return name;}
    int get_helth() {return health;}
    int get_xp() {return xp;}
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0 );
    // Copy constructor
    Player (const Player &source);
    // Destructor
    ~Player(){ cout<<"Destructor called for: "<< name << endl;}
};

Player::Player(std::string name_val, int health_val, int xp_val)        
    :name{name_val}, health{health_val}, xp{xp_val}{
    cout<<"three args constructor is called for " + name << endl;
}

Player::Player(const Player &source)
    :name{source.name}, health{source.health}, xp{source.xp}{
    cout<<"three args constructor is called for " << source.name << endl;
}

void display_player (Player p)
{
    cout<< "Name: "<<p.get_name()<<endl;
    cout<< "helth: "<<p.get_helth()<<endl;
    cout<< "xp: "<<p.get_xp() <<endl;

}

int main()
{
    Player empty;

    display_player (empty);

    Player frank {"Frank"};
    Player hero {"Hero, 100"};
    Player villain {"Villain", 100, 55};
    return 0;
}