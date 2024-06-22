#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;

    int takahashiScore = 0;
    int aokiScore = 0;

    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        takahashiScore += x;
        aokiScore += y;
    }

    if (takahashiScore > aokiScore)
    {
        cout << "Takahashi" << endl;
    }
    else if (aokiScore > takahashiScore)
    {
        cout << "Aoki" << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }

    return 0;
}
