/*
This code is an accepted solution to:
https://codeforces.com/contest/1339/problem/C
Problem C: Powered Addition
During a 2-hour contest: Codeforces Round #633
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool already_sorted = true;
        int x = 1;
        long long pow_2 = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i-1]) {
                already_sorted = false;
                if (a[i-1]-a[i] > pow_2) {
                    x = max(x, static_cast<int>((log2(a[i-1]-a[i])))+1);
                    pow_2 = pow(2, x-1);
                }
                a[i] = a[i-1];
            }
        }

        if (already_sorted) {
            cout << 0 << endl;
        }
        else {
            cout << x << endl;
        }

    }
    return 0;
}
