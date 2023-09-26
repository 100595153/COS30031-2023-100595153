#include <iostream>
#include "Player.h"

using namespace std;

void print_player(Player* player)
{
    cout 
        << "Player:" << endl
        << "Type: " << player->_type << endl
        << "Health: " << player->_health << endl
        << "Mana: " << player->_mana << endl << endl;
}

int main()
{
    Player* player = new Player('A', 95, 1.2);

    print_player(player);
}
