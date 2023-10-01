#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main()
{
    ifstream input_file("world1.json");
    json data = json::parse(input_file);
    input_file.close();

    cout << data["locations"] << endl;

    for (json loc : data["locations"])
    {
        cout << loc << endl;
    }
}
