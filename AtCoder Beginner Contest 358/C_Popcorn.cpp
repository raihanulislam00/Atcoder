#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
   cin >> N >> M;

   vector<std::string> stands(N);
    for (int i = 0; i < N; ++i) {
       cin >> stands[i];
    }

    int all_flavors = (1 << M) - 1; 
    int min_stands = INT_MAX;

    for (int subset = 1; subset < (1 << N); ++subset) {
        int flavor_mask = 0;
        int stands_count = 0;

        for (int i = 0; i < N; ++i) {
            if (subset & (1 << i)) {
                stands_count++;
                for (int j = 0; j < M; ++j) {
                    if (stands[i][j] == 'o') {
                        flavor_mask |= (1 << j);
                    }
                }
            }
        }

        if (flavor_mask == all_flavors) {
            min_stands =min(min_stands, stands_count);
        }
    }

   cout << min_stands <<endl;

    return 0;
}
