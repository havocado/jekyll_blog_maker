/*
This code is an accepted solution to:
https://codeforces.com/contest/1339/problem/B
Problem B: Sorted Adjacent Differences
During a 2-hour contest: Codeforces Round #633
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (n%2 == 1) {
            cout << a[n/2] << " ";
            for (int i = n/2-1; i >= 0; i--) {
                cout << a[n-i-1] << " " << a[i] << " ";
            }
        }
        else {
            for (int i = n/2-1; i >= 0; i--) {
                cout << a[n-i-1] << " " << a[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
