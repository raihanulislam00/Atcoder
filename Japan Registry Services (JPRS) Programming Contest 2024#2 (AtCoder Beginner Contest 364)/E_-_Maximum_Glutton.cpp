#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X, Y;
    cin >> N >> X >> Y;

    vector dp(N + 1, vector<int>(X + 1, Y + 1));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;

        for (int c = i; c >= 0; c--)
        {
            for (int d = X; d >= A; d--)
            {
                dp[c + 1][d] = min(dp[c + 1][d], dp[c][d - A] + B);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int x = 0; x <= X; x++)
        {
            if (dp[i][x] <= Y)
            {
                ans = max(ans, i + 1);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
