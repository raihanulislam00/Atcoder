#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define int long long
int32_t main()
{
    int n, m;
    cin >> n >> m;

    vector<int> s(n + 1, 0);
    map<int, int> cnt_amp = {{0, n}};

    int i = 0;
    while (i < m)
    {
        int a, b;
        cin >> a >> b;

        if (--cnt_amp[s[a]] == 0)
            cnt_amp.erase(s[a]);

        cnt_amp[s[a] += b]++;
        cout << cnt_amp.size() << endl;

        i++;
    }

    return 0;
}
