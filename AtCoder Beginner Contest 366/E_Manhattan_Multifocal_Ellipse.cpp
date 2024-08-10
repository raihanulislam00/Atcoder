#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using ll = long long;

const ll MX = 4000005;

int main()
{
    FAST;

    ll n, d, i, cx, x, y, dx, dy, rem, l, r, mid, xl, xr, ans;
    cin >> n >> d;

    vector<ll> ax(n), ay(n);
    for (i = 0; i < n; ++i)
        cin >> ax[i] >> ay[i];
    for (i = 0; i < n; ++i)
        ax[i] += 2000005;
    sort(ax.begin(), ax.end());
    sort(ay.begin(), ay.end());

    cx = ax[(n - 1) / 2];
    dx = 0;
    for (i = 0; i < n; ++i)
        dx += abs(cx - ax[i]);

    vector<ll> dis_at(MX * 4 + 1, 0);
    x = 0;
    dx = 0;
    for (i = 0; i < n; ++i)
        dx += abs(x - ax[i]);
    for (x = 1; x <= MX * 4; ++x)
    {
        i = lower_bound(ax.begin(), ax.end(), x) - ax.begin();
        dx -= n - i;
        dx += i;
        dis_at[x] = dx;
    }

    y = -MX;
    dy = 0;
    for (i = 0; i < n; ++i)
        dy += abs(y - ay[i]);

    ans = 0;
    for (y = -MX; y <= MX; ++y)
    {
        // calc
        rem = d - dy;
        if (dis_at[cx] <= rem)
        {
            l = 0;
            r = cx;
            xl = r;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (dis_at[mid] <= rem)
                {
                    xl = min(xl, mid);
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }

            l = cx;
            r = MX * 4;
            xr = l;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (dis_at[mid] <= rem)
                {
                    xr = max(xr, mid);
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }

            ans += xr - xl + 1;
        }

        // update
        i = lower_bound(ay.begin(), ay.end(), y + 1) - ay.begin();
        dy -= n - i;
        dy += i;
    }

    cout << ans << "\n";

    return 0;
}
