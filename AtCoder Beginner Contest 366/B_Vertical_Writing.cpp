#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);

    int maxLength = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> S[i];
        maxLength = max(maxLength, (int)S[i].length());
    }
    vector<string> T(maxLength, string(N, '*'));

    for (int i = 0; i < N; ++i)
    {
        int row = N - i - 1;
        for (int j = 0; j < S[i].length(); ++j)
        {
            T[j][row] = S[i][j];
        }
    }

    for (int i = 0; i < maxLength; ++i)
    {
        int len = T[i].length();
        while (len > 0 && T[i][len - 1] == '*')
        {
            --len;
        }
        cout << T[i].substr(0, len) << endl;
    }

    return 0;
}
