#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        if (v[i] == "sweet" && v[i + 1] == "sweet")
        {
            if (i + 1 != N - 1)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
