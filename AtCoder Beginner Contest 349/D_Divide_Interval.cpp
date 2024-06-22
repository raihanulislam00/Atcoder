#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define int long long
int32_t main() {
    int L, R;
    cin >> L >> R;
    vector<pair<int, int>> v;
    int curr = L;
    while (curr < R) {
        int pt = 1, ei = curr + 1;
        for (int i = 0; i <= 60 && curr + pt <= R; i++) {
            if (curr % pt == 0) ei = curr + pt;
            pt <<= 1LL;
        }
        v.emplace_back(curr, ei);
        curr = ei;
    }
    cout << v.size() << endl;
    for (const auto& interval : v) {
        cout << interval.first << " " << interval.second << endl;
    }
    return 0;
}
