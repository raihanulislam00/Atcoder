#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
struct DSU
{
    vector<int> f, siz;

    DSU() {}
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> L(Q), R(Q), C(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> L[i] >> R[i] >> C[i];
        L[i]--;
    }

    vector<int> p(Q);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(),
         [&](int i, int j)
         {
             return C[i] < C[j];
         });

    DSU dsu(N);
    i64 ans = 0;
    for (auto i : p)
    {
        ans += C[i];
        for (int x = dsu.find(L[i]); x < R[i] - 1; x = dsu.find(x))
        {
            dsu.merge(x + 1, x);
            ans += C[i];
        }
    }
    if (dsu.find(0) != N - 1)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ans << "\n";
    }

    return 0;
}
