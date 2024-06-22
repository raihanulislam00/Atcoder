#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // Input
    int H, W, N;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    vector<string> S(H);
    for (int i = 0; i < H; ++i)
    {
        cin >> S[i];
    }

    // Simulation
    int count = 0;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            // Skip if it's sea
            if (S[i][j] == '#')
                continue;

            int x = i, y = j;
            bool possible = true;

            // Simulate Takahashi's movements
            for (char move : T)
            {
                if (move == 'L')
                    y--;
                else if (move == 'R')
                    y++;
                else if (move == 'U')
                    x--;
                else if (move == 'D')
                    x++;

                // Check if out of grid or on sea
                if (x < 0 || x >= H || y < 0 || y >= W || S[x][y] == '#')
                {
                    possible = false;
                    break;
                }
            }

            // Increment count if possible
            if (possible)
                count++;
        }
    }

    // Output
    cout << count << endl;

    return 0;
}
