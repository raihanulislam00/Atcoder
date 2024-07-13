#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int R, G, B;
    string C;

    cin >> R >> G >> B;
    cin >> C;

    int minPrice;
    if (C == "Red")
    {
        minPrice = min(G, B);
    }
    else if (C == "Green")
    {
        minPrice = min(R, B);
    }
    else if (C == "Blue")
    {
        minPrice = min(R, G);
    }

    cout << minPrice << endl;

    return 0;
}
