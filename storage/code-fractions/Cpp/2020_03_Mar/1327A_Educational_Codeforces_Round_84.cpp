/*
This code is an accepted solution to:
https://codeforces.com/contest/1327/problem/A
During a 2-hour contest : Educational Codeforces Round 84
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        long long n, k;
        cin >> n >> k;
        // Sum of 1, 3, 5, ... : k^2.
        if (n >= k*k && (n - k*k)%2 == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
