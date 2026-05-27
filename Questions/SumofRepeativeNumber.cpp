#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> input(n);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[input[i]]++;
    }

    int sum = 0;
    for (auto elem : m)
    {
        if (elem.second > 1)
            sum += elem.first;
    }

    cout << sum << endl;

    return 0;
}