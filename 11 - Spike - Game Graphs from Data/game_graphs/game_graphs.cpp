#include <iostream>
#include <fstream>
#include "json.hpp"
#include "Location.h"

using json = nlohmann::json;
using namespace std;

int main(int argc, char** argv)
{
    if (argc < 2)
        return 1;

    vector<Location*> locations;

    ifstream input_file(argv[1]);
    json data = json::parse(input_file);
    input_file.close();

    for (json loc : data["locations"])
    {
        locations.push_back(new Location(loc));
    }

    cout << "Location Test" << endl;

    for (Location* loc : locations)
    {
        cout << "Name: " << loc->getName() << " - " << loc->getDesc() << endl;
        cout << "Is there east?: " << loc->findConnection("east") << endl;

        cout << "Connections: ";
        loc->showConnections();

        cout << "Find me the sword: " << loc->findItem("sword") << endl;

        cout << "Show me what you got: " << endl;
        loc->viewItems();

        cout << "Add a gun: " << loc->addItem(new Item("a gun lol", "blam blam.")) << endl;
        cout << "Remove a gun: " << loc->removeItem("a gun lol") << endl;

        cout << endl;
    }

    return 0;
}
