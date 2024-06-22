#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    unordered_map<int, int> mapping;
    for (int i = 0; i < N; ++i)
    {
        mapping[A[i]] = i + 1;
    }

    int current_index = mapping[-1];
    vector<int> result{current_index};

    for (int i = 0; i < N - 1; ++i)
    {
        current_index = mapping[current_index];
        result.push_back(current_index);
    }

    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}
