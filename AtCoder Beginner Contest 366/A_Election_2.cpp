#include <iostream>
using namespace std;

int main()
{
    int n, t, a;

    // Input values for n, t, and a
    cin >> n >> t >> a;

    // Calculate m
    int m = (n / 2) + 1;

    // Check the conditions and print the appropriate result
    if (t >= m || a >= m)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}