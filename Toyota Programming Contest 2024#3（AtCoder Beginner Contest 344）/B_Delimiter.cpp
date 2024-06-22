#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> numbers;
    int num;

    while (cin >> num && num != 0)
    {
        numbers.push_back(num);
    }
    cout << "0" << endl;
    for (int i = numbers.size() - 1; i >= 0; --i)
    {
        cout << numbers[i] << endl;
    }

    return 0;
}
