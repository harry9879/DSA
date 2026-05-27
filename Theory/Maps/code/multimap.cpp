#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<string, int> directory;

    directory.insert(make_pair("urvi", 6292001));
    directory.insert(make_pair("ravi", 4435453));
    directory.insert(make_pair("urvi", 577881));

    // directory["urvi"] = 323243; wrong

    for (auto pair : directory)
    {
        cout << "Name -" << pair.first << endl;
        cout << "Phone no -" << pair.second << endl;
    }

    return 0;
}