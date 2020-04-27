/*
This code is an accepted solution to:
https://codeforces.com/contest/1323/problem/A
During a 2-hour Virtual Contest :
Codeforces Round #626 (Div. 2, based on Moscow Open Olympiad in Informatics)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            if (a[0]%2 == 1) {
                cout << -1 << endl;
            }
            else {
                cout << 1 << endl << 1 << endl;
            }
        }
        else if (a[0]%2 == 0) {
            cout << 1 << endl << 1 << endl;
        }
        else if (a[1]%2 == 0) {
            cout << 1 << endl << 2 << endl;
        }
        else {
            cout << 2 << endl << "1 2" << endl;
        }
    }
    return 0;
}
