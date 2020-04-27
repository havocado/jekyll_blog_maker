/*
This code is an accepted solution to:
https://codeforces.com/contest/1333/problem/A
1333A, Little Artem
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, m;
        cin >> n >> m;

        if (n == 2 && m == 3) {
            for (int j = 0; j < m; j++) {
                if (j < 3) {
                    cout << 'B';
                }
                else {
                    cout << 'W';
                }
            }
            cout << endl;
            for (int j = 0; j < m; j++) {
                if (j == 1) {
                    cout << 'B';
                }
                else {
                    cout << 'W';
                }
            }
            cout << endl;
        }
        else if (n == 2 && m > n) {
            for (int j = 0; j < m; j++) {
                if (j < 2) {
                    cout << 'B';
                }
                else {
                    cout << 'W';
                }
            }
            cout << endl;
            for (int j = 0; j < m; j++) {
                if (j == 1 || j == 2) {
                    cout << 'B';
                }
                else {
                    cout << 'W';
                }
            }
            cout << endl;
        }
        else if (n >= m) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (j <= i) {
                        cout << 'B';
                    }
                    else {
                        cout << 'W';
                    }
                }
                cout << endl;
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == n-1 && j == 0) {
                        cout << 'W';
                    }
                    else if (j <= i) {
                        cout << 'B';
                    }
                    else {
                        cout << 'W';
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
