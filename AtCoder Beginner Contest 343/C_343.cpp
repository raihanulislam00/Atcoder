#include <iostream>
#include <string>
using namespace std;
#define int long long
int32_t main()
{
    int N;
    cin >> N;

    int result = 0;

    for (int i = 1; i * i * i <= N; ++i)
    {
        int cube = i * i * i;
        
        string str = to_string(cube);
        int len = str.length();
        bool flag = true;
        
        for (int j = 0; j < len / 2; ++j)
        {
            if (str[j] != str[len - j - 1])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            result = cube;
        }
    }

    cout << result << endl;

    return 0;
}
