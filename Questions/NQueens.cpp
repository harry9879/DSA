#include <iostream>
#include <vector>
using namespace std;

void nqueen(int currRow, int n, vector<vector<char>> &grid)
{
    if (currRow == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // TODO: Add your code here

    return 0;
}
