#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string S, sortedS;
    cin >> S;

    sortedS = S;

    sort(sortedS.begin(), sortedS.end());

    if (S == sortedS)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
