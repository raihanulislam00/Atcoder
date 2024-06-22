#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, A;
   cin >> N >> A;

   vector<int> T(N);
    for (int i = 0; i < N; ++i) {
       cin >> T[i];
    }

    int current_time = 0;

    for (int i = 0; i < N; ++i) {
        if (T[i] > current_time) {
            // Person arrives after the current free time of the booth
            current_time = T[i] + A;
        } else {
            // Person arrives while the booth is still busy
            current_time += A;
        }
       cout << current_time <<endl;
    }

    return 0;
}
