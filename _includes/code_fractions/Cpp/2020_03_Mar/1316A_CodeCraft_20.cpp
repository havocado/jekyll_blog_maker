/*
This code is an accepted solution to:
https://codeforces.com/contest/1316/problem/A
During a 2-hour contest : CodeCraft-20 (Div. 2)
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        int total = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
        }
        cout << min(total, m) << endl;
    }
    return 0;
}
