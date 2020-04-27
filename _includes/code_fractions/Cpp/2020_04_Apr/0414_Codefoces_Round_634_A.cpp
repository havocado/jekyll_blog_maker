/*
This code is an accepted solution to:
https://codeforces.com/contest/1335/problem/A
Problem A: Candies and Two Sisters
During a 2-hour contest: Codeforces Round #634
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        cout << max(0, (n+1)/2 - 1) << endl;
    }

    return 0;
}
