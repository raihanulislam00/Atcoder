#include <iostream>
#include <vector>

using namespace std;
#define ll long long



int main()
{
    int N;
    cin >> N;
    vector<ll> arr(N);
    for (auto &i : arr)
        cin >> i;
    vector<ll> s, t;
    for (int i = 1; i < N; ++i)
    {
        ll a, b;
        cin >> a >> b;
        s.push_back(a);
        t.push_back(b);
    }
    for (int i = 1; i < N; ++i)
    {
        ll val = (arr[i - 1] / max(1LL, s[i - 1])) * t[i - 1];
        arr[i] += val;
    }
    cout << arr[N - 1] << endl;
    return 0;
}
