/*
This code is an accepted solution to:
https://codeforces.com/contest/1260/problem/C
Tags: greedy, math, number theory, *1700
*/
#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        long long r, b, k;
        cin >> r >> b >> k;
        long long rbgcd = gcd(r, b);
        if (r*k < b || b*k < r || (rbgcd+b*(k-1) < r) || (rbgcd+r*(k-1)<b)) {
            cout << "REBEL" << endl;
        }
        else {
            cout << "OBEY" << endl;
        }
    }
    return 0;
}
