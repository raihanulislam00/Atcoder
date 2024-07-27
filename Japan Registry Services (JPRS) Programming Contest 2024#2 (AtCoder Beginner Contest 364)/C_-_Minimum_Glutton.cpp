#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    i64 X, Y;
    cin >> N >> X >> Y;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    int ans = N;
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());

    for (int i = 0; i < N; i++)
    {
        X -= A[i];
        if (X < 0)
        {
            ans = min(ans, i + 1);
        }
    }
    for (int i = 0; i < N; i++)
    {
        Y -= B[i];
        if (Y < 0)
        {
            ans = min(ans, i + 1);
        }
    }
    cout << ans << "\n";

    return 0;
}
