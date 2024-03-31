#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    string name;
    int health;
    int xp;
public:
    void setname(string name_val)
    {
        name = name_val;
    }
    //overload constructors
    Player()
    {
        cout<<"No argument contructor is called"<<endl;
    }
    Player(string name)
    {
        cout<<"String argument contructor is called"<<endl;
    }
    Player(string name, int health, int xp)
    {
        cout<<"Three arguments contructor is called"<<endl;
    }
    ~Player()
    {
        cout<<"Destructor is called for "<<name<<endl;
    }
};

int main()
{
    {
        Player slayer;
        slayer.setname("Slayer");
    }
    
    { 
        Player frank;
        frank.setname("Frank");
        Player hero;
        hero.setname("hero");
        Player violet("Violet", 100, 12);
        violet.setname("Violet");
    }

    Player *enemy = new Player;
    enemy->setname("enemy");

    Player *level_boss = new Player ("Level Boss", 1000, 300);
    level_boss->setname("Level Boss");

    delete enemy;
    delete level_boss;
    return 0;
}