/*
This code is an accepted solution to:
https://codeforces.com/contest/1328/problem/C
During a 2-hour contest : Codeforces Round 629
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        vector<char> x(n);
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < n; i++) {
            if (x[i] == '2') {
                a[i] = 1;
                b[i] = 1;
            }
            else if (x[i] == '0') {
                a[i] = 0;
                b[i] = 0;
            }
            else {
                a[i] = 1;
                b[i] = 0;
                for (int j = i+1; j < n; j++) {
                    a[j] = 0;
                    b[j] = x[j] - '0';
                }
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << b[i];
        }
        cout << endl;
    }
    return 0;
}
