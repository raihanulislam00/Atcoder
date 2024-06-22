#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main()
{
    int N, M, L, Q;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> B[i];
    }
    cin >> L;
    vector<int> C(L);
    for (int i = 0; i < L; ++i)
    {
        cin >> C[i];
    }
    cin >> Q;
    vector<int> X(Q);
    for (int i = 0; i < Q; ++i)
    {
        cin >> X[i];
    }
    unordered_set<int> sums_AB;
    for (int a : A)
    {
        for (int b : B)
        {
            sums_AB.insert(a + b);
        }
    }

    for (int i = 0; i < Q; ++i)
    {
        bool possible = false;
        for (int c : C)
        {
            if (sums_AB.find(X[i] - c) != sums_AB.end())
            {
                possible = true;
                break;
            }
        }
        cout << (possible ? "Yes" : "No") << endl;
    }

    return 0;
}
