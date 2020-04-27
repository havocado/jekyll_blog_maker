/*
This code is an accepted solution to:
https://codeforces.com/contest/1326/problem/B
During a 2-hour contest : Codeforces Global Round 7
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> a(n);
    vector<int> x(n);
    x[0] = 0;

    for (int i = 0; i < n; i++) {
        // b = a-x. -> b+x = a.
        a[i] = b[i] + x[i];
        if (i+1 < n) {
            x[i+1] = max(x[i], a[i]);
        }
    }

    // Output
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
