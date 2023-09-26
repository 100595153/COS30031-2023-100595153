#include <iostream>
#include <fstream>

using namespace std;

struct Player
{
    char type;
    int health;
    float mana;
};

void print_player(Player player)
{
    cout 
        << "Player:" << endl
        << "Type: " << player.type << endl
        << "Health: " << player.health << endl
        << "Mana: " << player.mana << endl << endl;
}

void partA()
{
    Player player = { 'X', 95, 1.2f };

    print_player(player);

    ofstream output_file;
    output_file.open("test1.bin", ios::out | ios::binary);

    if (output_file.is_open())
    {
        output_file.write(reinterpret_cast<char*>(&player.type), sizeof(char));
        output_file.write(reinterpret_cast<char*>(&player.health), sizeof(int));
        output_file.write(reinterpret_cast<char*>(&player.mana), sizeof(float));

        output_file.close();
        cout << "File writing confirmed." << endl;
    }
    else
        cout << "Error writing to file.";

    player = { 'A', 0, 0.0f };

    ifstream input_file;
    input_file.open("test1.bin", ios::in | ios::binary);
    if (input_file.is_open())
    {
        input_file.read(reinterpret_cast<char*>(&player.type), sizeof(char));
        input_file.read(reinterpret_cast<char*>(&player.health), sizeof(int));
        input_file.read(reinterpret_cast<char*>(&player.mana), sizeof(float));

        input_file.close();
        cout << "File reading confirmed." << endl << endl;
    }
    else
        cout << "Error writing to file.";

    print_player(player);
}

int main()
{
    partA();

    //partB();

    return 0;
}
