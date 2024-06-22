#include <iostream>
#include <string>
using namespace std;
int main()
{
    string S;
    cin >> S;

    // Find the positions of the two '|' characters
    int first_pipe = S.find('|');
    int last_pipe = S.rfind('|');

    // Remove the characters between the two '|' characters
    string result = S.substr(0, first_pipe) + S.substr(last_pipe + 1);

    cout << result << endl;

    return 0;
}
