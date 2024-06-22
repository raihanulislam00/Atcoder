#include<bits/stdc++.h>
using namespace std;
int main()
{
    int rows, c, m;
    cin >> rows >> c >> m;

    int temp = 0;
    pair<int, int> cp = {0, 0};
    vector<vector<char>> grid(rows, vector<char>(c, '.')); // Initialize grid with all cells white

    for (int i = 0; i < m; ++i)
    {
        if (grid[cp.first][cp.second] == '.')
        {
            grid[cp.first][cp.second] = '#';
            temp = (temp + 1) % 4;
        }
        else
        {
            grid[cp.first][cp.second] = '.';
            temp = (temp - 1 + 4) % 4;
        }

        if (temp == 0)
        { // Up
            cp.first = (cp.first - 1 + rows) % rows;
        }
        else if (temp == 1)
        { // Right
            cp.second = (cp.second + 1) % c;
        }
        else if (temp == 2)
        { // Down
            cp.first = (cp.first + 1) % rows;
        }
        else if (temp == 3)
        { // Left
            cp.second = (cp.second - 1 + c) % c;
        }
    }

    // Print the final grid
    for (const auto &row : grid)
    {
        for (char cell : row)
        {
            cout << cell;
        }
        cout << endl;
    }

    return 0;
}
