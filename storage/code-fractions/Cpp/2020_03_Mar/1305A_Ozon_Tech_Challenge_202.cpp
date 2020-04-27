/*
This code is an accepted solution to:
https://codeforces.com/contest/1305/problem/A
During a 2-hour contest : Ozon Tech Challenge 2020
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;

    }
    return 0;
}
