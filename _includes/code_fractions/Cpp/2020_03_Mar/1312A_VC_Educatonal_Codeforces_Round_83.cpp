/*
This code is an accepted solution to:
https://codeforces.com/contest/1312/problem/A
During a 2-hour Virtual Contest : Educational Codeforces Round 83
*/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        int a, b;
        cin >> a >> b;
        if (a%b==0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
