#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    int Si, Sj;
    cin >> Si >> Sj;
    Si--;
    Sj--;

    vector<string> grid(H);
    for (int i = 0; i < H; ++i)
    {
        cin >> grid[i];
    }

    string X;
    cin >> X;

    int x = Si, y = Sj;
    for (char move : X)
    {
        if (move == 'L' && y > 0 && grid[x][y - 1] == '.')
        {
            y--;
        }
        else if (move == 'R' && y < W - 1 && grid[x][y + 1] == '.')
        {
            y++;
        }
        else if (move == 'U' && x > 0 && grid[x - 1][y] == '.')
        {
            x--;
        }
        else if (move == 'D' && x < H - 1 && grid[x + 1][y] == '.')
        {
            x++;
        }
    }
    cout << (x + 1) << " " << (y + 1) << endl;

    return 0;
}
