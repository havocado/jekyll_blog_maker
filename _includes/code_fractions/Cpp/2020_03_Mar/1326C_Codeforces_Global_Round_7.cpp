/*
This code is an accepted solution to:
https://codeforces.com/contest/1326/problem/C
During a 2-hour contest : Codeforces Global Round 7
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> p(n);
    vector<long long> pivots;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] > n-k) {
            pivots.push_back(i);
        }
    }

    long long first = ((2*n-k+1)*k)/2;
    long long second = 1;
    for (int i = 0; i < k-1; i++) {
        second *= (pivots[i+1]-pivots[i]);
        second %= 998244353;
    }

    cout << first << " " << second << endl;

    return 0;
}
