/*
This code is an accepted solution to:
https://codeforces.com/contest/1326/problem/A
During a 2-hour contest : Codeforces Global Round 7
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        int n;
        cin >> n;
        /*
        if n = 1, impossible.
        if n = 2, 23 does it.
        if n = 3, 223 does it.
           n = 4, 2233. (instead of 2223, because of 3)
           ....
        */
        if (n == 1) {
            cout << -1 << endl;
        }
        else if (n%3 == 1) {
            for (int i = 0; i < n-2; i++) {
                cout << 2;
            }
            cout << 33 << endl;
        }
        else {
            for (int i = 0; i < n-1; i++) {
                cout << 2;
            }
            cout << 3 << endl;
        }
    }
    return 0;
}
