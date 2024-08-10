#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    unordered_map<int, int> bag;
    int queryType, x;

    while (Q--)
    {
        cin >> queryType;
        if (queryType == 1)
        {
            cin >> x;
            bag[x]++;
        }
        else if (queryType == 2)
        {
            cin >> x;
            if (--bag[x] == 0)
            {
                bag.erase(x);
            }
        }
        else if (queryType == 3)
        {
            cout << bag.size() << '\n';
        }
    }

    return 0;
}
