#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int N_sum = 0;
    int c_sum = 0;

    for (int i = 0; i < n; i++)
    {
        c_sum += arr[i];
        if (c_sum < 0)
        {
            N_sum += (-c_sum);
            c_sum = 0;
        }
    }

    c_sum = 0;
    for (int i = 0; i < n; i++)
    {
        c_sum += arr[i];
    }

    cout << c_sum + N_sum << endl;
    return 0;
}
