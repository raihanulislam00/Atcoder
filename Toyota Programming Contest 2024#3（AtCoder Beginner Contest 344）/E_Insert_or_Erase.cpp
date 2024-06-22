#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
int main()
{
    int N;
    cin >> N;

    list<int> A;
    unordered_map<int, list<int>::iterator> index;

    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        A.push_back(num);
        index[num] = prev(A.end());
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        int type, x, y;
        cin >> type >> x;

        if (type == 1)
        {
            cin >> y;
            auto it = index[x];
            ++it;                 
            A.insert(it, y);      
            index[y] = prev(it); 
        }
        else
        {
            auto it = index[x];
            index.erase(x); 
            A.erase(it);   
        }
    }

    
    for (int num : A)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
