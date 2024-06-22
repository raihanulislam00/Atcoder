#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = INT_MAX;
    vector<vector<pair<int, int>>> row(n, vector<pair<int, int>>(m, {0, 0}));

    for (int i = 0; i < n; i++)
    {
        int f = -1;
        int r = 0;

        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'x')
            {
                r = 0, f = j;
            }
            else
            {
                if (v[i][j] == '.')
                {
                    r++;
                }

                if ((j - k >= -1) && (j - k + 1) > f)
                {
                    int time = r - ((j - k) >= 0 ? row[i][j - k].second : 0);
                    row[i][j] = {1, r};
                    ans = min(ans, time);
                }
                else
                {
                    row[i][j] = {0, r};
                }
            }
        }
    }

    vector<vector<pair<int, int>>> col(m, vector<pair<int, int>>(n, {0, 0}));

    for (int i = 0; i < m; i++)
    {
        int f = -1;
        int r = 0;

        for (int j = 0; j < n; j++)
        {
            if (v[j][i] == 'x')
            {
                r = 0, f = j;
            }
            else
            {
                if (v[j][i] == '.')
                {
                    r++;
                }

                if ((j - k >= -1) && (j - k + 1) > f)
                {
                    int time = r - ((j - k) >= 0 ? col[i][j - k].second : 0);
                    col[i][j] = {1, r};
                    ans = min(ans, time);
                }
                else
                {
                    col[i][j] = {0, r};
                }
            }
        }
    }

    if (ans == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }

    return 0;
}
