/*
This code is an accepted solution to:
https://codeforces.com/contest/1335/problem/B
Problem B: Construct the String
During a 2-hour contest: Codeforces Round #634
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, a, b;
        cin >> n >> a >> b;
        for (int i = 0; i < n; i++) {
            if (i%a < b) {
                cout << static_cast<char>('a'+i%a);
            }
            else {
                cout << 'a';
            }
        }
        cout << endl;
    }

    return 0;
}
