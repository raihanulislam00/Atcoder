#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int sum = A + B;

    int result = -1;
    for (int i = 0; i <= 9; ++i) {
        if (i != sum) {
            result = i;
            break;
        }
    }

    cout << result << endl;

    return 0;
}
