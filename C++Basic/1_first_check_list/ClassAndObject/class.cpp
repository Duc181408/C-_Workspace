#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
    // attributes
    string name;
    int health;
    int xp;
    // methods
    void talk(string);
    bool is_dead1(string);
};


int main()
{
    Player frank;
    Player hero;

    Player players[2] = {frank, hero};

    vector <Player> player_vect {frank};
    player_vect.push_back (hero);
    
    Player *enemy {nullptr};
    enemy = new Player;

    delete enemy;

    cout << "Helloo" << endl;
    return 0;
}

