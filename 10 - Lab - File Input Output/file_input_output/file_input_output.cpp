#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;
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

string sanitize_input(string line)
{
    while (!line.empty() && line.front() == ' ')
    {
        line.erase(0);
    }
    return line;
}

vector<string> split_string(string line)
{
    size_t pos = 0;
    string token;
    string delimiter = ":";
    vector<string> split;
    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        split.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    split.push_back(line);
    return split;
}

void partB()
{
    string line;

    ifstream input_file;
    input_file.open("test2.txt", ios::in);
    if (input_file.is_open())
    {
        while (getline(input_file, line))
        {
            if (!line.empty() && line.front() != '#')
            {
                for (string s : split_string(line))
                {
                    cout << s << endl;
                }
            }
        }

        input_file.close();
    }
    else
        cout << "Error writing to file.";
}

void partC()
{
    ifstream input_file("test3.json");
    json data = json::parse(input_file);
    input_file.close();

    cout << data.dump(1) << endl;
}

int main()
{
    partA();

    partB();

    partC();

    return 0;
}
