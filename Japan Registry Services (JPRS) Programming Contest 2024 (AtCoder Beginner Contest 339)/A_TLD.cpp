#include <bits/stdc++.h>
using namespace std;
int main()
{
    string inputString;
    cin >> inputString;

    size_t dotPosition = inputString.find_last_of('.');

    string lastSubstring = inputString.substr(dotPosition + 1);

    cout << lastSubstring << endl;

    return 0;
}
