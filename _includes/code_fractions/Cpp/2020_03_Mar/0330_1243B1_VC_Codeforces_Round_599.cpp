/*
This code is an accepted solution to:
https://codeforces.com/contest/1243/problem/B1
During a 2-hour Virtual Contest : Codeforces Round 599
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int k;
    cin >> k;
    for (int tc = 0; tc < k; tc++) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        bool possible = true;
        int first, second;
        int diffCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                diffCount++;
                if (diffCount == 1) {
                    first = i;
                }
                else if (diffCount == 2) {
                    second = i;
                }
                else {
                    possible = false;
                    break;
                }
            }
        }
        if (diffCount == 0) {
            first = 0;
            second = 0;
        }
        if (diffCount == 1) {
            possible = false;
        }
        else {
            //diffCount == 2 or 0
            if (!(s[first] == s[second] && t[second] == t[first])) {
                possible = false;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
