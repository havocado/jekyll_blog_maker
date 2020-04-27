/*
This code is an accepted solution to:
https://codeforces.com/contest/160/problem/A
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int coinsTotal = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        coinsTotal += a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i];
        if (total*2 > coinsTotal) {
            cout << i+1 << endl;
            break;
        }
    }

    return 0;
}
