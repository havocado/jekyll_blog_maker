/*
This code is an accepted solution to:
https://codeforces.com/contest/1313/problem/A
During a 2-hour contest : Codeforces Round #622 (Div. 2)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);
        reverse(a, a+3);
        // possible:
        // 001, 010, 100, 011, 101, 110, 111.
        int count = 0;
        for (int i = 0; i < 3; i++) {
            if (a[i] > 0) {
                // cout << "case A " << i << endl;
                count++;
                a[i]--;
            }
        }
        // now 001, 010, 100 case are done.
        // a[i] is at most 2 here.
        if (a[0] > 0 && a[1] > 0) {
            // cout << "case B" << endl;
            count++;
            a[0]--;
            a[1]--;
        }
        if (a[0] > 0 && a[2] > 0) {
            // cout << "case C" << endl;
            count++;
            a[0]--;
            a[2]--;
        }
        if (a[1] > 0 && a[2] > 0) {
            // cout << "case D" << endl;
            count++;
            a[1]--;
            a[2]--;
        }
        if (a[0] > 0 && a[1] > 0 && a[2] > 0) {
            // cout << "case E" << endl;
            count++;
        }
        cout << count << endl;

    }

    return 0;
}
