#include<bits/stdc++.h>
using namespace std;

string Raihan(string s, string t) {
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (toupper(s[i]) == t[0]) {
            for (int j = i + 1; j < n; ++j) {
                if (toupper(s[j]) == t[1]) {
                    if (t[2] == 'X') {
                        return "Yes";
                    }
                    for (int k = j + 1; k < n; ++k) {
                        if (toupper(s[k]) == t[2]) {
                            return "Yes";
                        }
                    }
                }
            }
        }
    }
    return "No";
}

int main() {
    string s, t;
    cin >> s >> t;

    cout << Raihan(s, t) << endl;

    return 0;
}