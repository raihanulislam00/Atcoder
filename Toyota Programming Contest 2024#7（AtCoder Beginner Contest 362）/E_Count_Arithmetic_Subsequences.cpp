#include <bits/stdc++.h>

using namespace std;
const int c = 85, mod = 998244353;
long long n, dp[c][c][c], t[c];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        for (int j = 1; j < i; j++)
        {
            dp[j][i][2] = 1;
        }
        for (int len = 2; len < i; len++)
        {
            for (int a = 1; a < i; a++)
            {
                for (int b = a + 1; b < i; b++)
                {
                    if (t[a] + t[i] == 2 * t[b])
                    {
                        dp[b][i][len + 1] = (dp[b][i][len + 1] + dp[a][b][len]) % mod;
                    }
                }
            }
        }
    }

    cout << n << " ";

    for (int len = 2; len <= n; len++)
    {
        long long sum = 0;
        for (int a = 1; a < n; a++)
        {
            for (int b = a + 1; b <= n; b++)
            {
                sum = (sum + dp[a][b][len]) % mod;
            }
        }
        cout << sum << " ";
    }
    cout << "\n";
    return 0;
}
