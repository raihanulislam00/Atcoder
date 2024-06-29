#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int cl(int x) {
    return (x + 1) / 2;
}

int main() {
    int N, ff, ans = 1;
    cin >> N;
    string s;
    cin >> s;
    s = ' ' + s; 

    ff = 1;
    for(int i = 2; i <= N; i++) {
        if(s[i] != s[i - 1]) {
            ff++;
        } else {
            ans = 1LL * ans * cl(ff) % MOD;
            ff = 1;
        }
    }
    ans = 1LL * ans * cl(ff) % MOD;
    cout << ans;
}
