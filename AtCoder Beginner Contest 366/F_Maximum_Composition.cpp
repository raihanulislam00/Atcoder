#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using ll = long long;

const ll MX = 17;
ll dp[1 << MX];
ll A[MX], B[MX];
ll m;

ll solve(ll mask)
{
    if (mask == 0)
        return 1;

    ll &curr = dp[mask];
    if (curr != -1)
        return curr;
    curr = 0;

    ll i, b;
    for (i = 0; i < m; ++i)
    {
        b = (1 << i);
        if (mask & b)
        {
            curr = max(curr, A[i] * solve(mask & ~b) + B[i]);
        }
    }

    return curr;
}

int main()
{
    FAST;
    memset(dp, -1, sizeof(dp));

    ll n, k, i, x, y, ans;
    cin >> n >> k;

    vector<pair<ll, ll>> a(n);
    for (i = 0; i < n; ++i)
    {
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(a.rbegin(), a.rend());

    m = min(n, MX);
    for (i = 0; i < m; ++i)
    {
        tie(A[i], B[i]) = a[i];
    }

    ans = 0;
    for (i = 0; i < (1 << MX); ++i)
    {
        if (__builtin_popcountll(i) == k)
        {
            ans = max(ans, solve(i));
        }
    }

    cout << ans << "\n";

    return 0;
}
