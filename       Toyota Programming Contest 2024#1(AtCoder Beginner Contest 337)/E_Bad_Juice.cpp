#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<vector<int>> a;
  for (int k = 0; k < 10; k++) {
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      if (i >> k & 1) {
        v.push_back(i);
      }
    }
    if (v.empty()) break;
    if (n == (1 << k)) break;
    a.push_back(v);
  }
  cout << a.size() << endl;
  for (auto v: a) {
    cout << v.size();
    for (auto x: v) cout << ' ' << x;
    cout << endl;
  }
  string s; cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      ans |= 1 << i;
    }
  }
  if (ans == 0) ans = n;
  cout << ans << endl;
  return 0;
}