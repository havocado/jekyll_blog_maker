/*
This code is an accepted solution to:
https://codeforces.com/contest/1328/problem/B
During a 2-hour contest : Codeforces Round 629
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        long long n, k;
        cin >> n >> k;
        int firstB, secondB;
        // decide the first b's position.
        // first b's index: n-m-1, obtained below:
        long long m;
        for (m = min(0, int(sqrt(2*k)-1)); m <= k; m++) {
            if (m*(m-1) < 2*k && 2*k <= m*(m+1)) {
                break;
            }
        }
        firstB = n-m-1;

        // decide the second b's position.
        secondB = n - (k - m*(m-1)/2);

        for (int i = 0; i < n; i++) {
            if (i == firstB || i == secondB) {
                cout << 'b';
            }
            else {
                cout << 'a';
            }
        }
        cout << endl;
    }
    return 0;
}
