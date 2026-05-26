#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> directory;

    directory["rumi"] = 48;
    directory["boni"] = 50;
    directory["hobin"] = 499;
    directory["samdak"] = 999;

    for (auto element : directory)
    {
        std::cout << element.first << " ";
        std::cout << element.second << " ";
    }
    return 0;
}