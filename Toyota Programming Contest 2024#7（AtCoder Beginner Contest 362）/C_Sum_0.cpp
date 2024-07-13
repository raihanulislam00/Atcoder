#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> L(N), R(N);
    long long sumL = 0, sumR = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> L[i] >> R[i];
        sumL += L[i];
        sumR += R[i];
    }

    if (sumL > 0 || sumR < 0)
    {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    vector<int> X(N);
    long long mahi = -sumL;

    for (int i = 0; i < N; ++i)
    {
        X[i] = L[i];
        long long mash = min((long long)R[i] - L[i], mahi);
        X[i] += mash;
        mahi -= mash;
    }

    for (int i = 0; i < N; ++i)
    {
        cout << X[i] << " ";
    }
    cout << endl;

    return 0;
}
