#include <iostream>
#include <fstream>
#include "json.hpp"
#include "Location.h"
#include "Manager.h"

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

    Manager manager = Manager(locations);

    while (manager.running())
    {
        manager.render();
        manager.update();
    }

    return 0;
}
