#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    string S;
    cin >> S;

    unordered_map<char, int> freq;

    for (char ch : S) {
        freq[ch]++;
    }

    unordered_map<int, int> cntfreq;

    for (const auto& pair : freq) {
        int count = pair.second;
        cntfreq[count]++;
    }

    bool flag = true;
    for (const auto& pair : cntfreq) {
        int count = pair.second;
        if (count != 0 && count != 2) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
