/*
This code is an accepted solution to:
https://codeforces.com/contest/1328/problem/A
During a 2-hour contest : Codeforces Round 629
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int a, b;
        cin >> a >> b;
        if (a % b == 0) {
            cout << 0 << endl;
        }
        else if (a >= b) {
            cout << b - a%b << endl;
        }
        else {
            cout << b - a << endl;
        }
    }
    return 0;
}
