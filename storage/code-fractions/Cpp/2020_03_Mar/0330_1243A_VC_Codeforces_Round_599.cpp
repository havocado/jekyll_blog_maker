/*
This code is an accepted solution to:
https://codeforces.com/contest/1243/problem/A
During a 2-hour Virtual Contest : Codeforces Round 599
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
        sort(a.begin(), a.end(), greater<int>());
        int result = n;
        for (int i = 0; i < n; i++) {
            if (a[i] < i+1) {
                result = i;
                break;
            }
        }
        cout << result << endl;
    }
    return 0;
}
