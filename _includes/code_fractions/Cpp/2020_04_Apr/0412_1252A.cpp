/*
This code is an accepted solution to:
https://codeforces.com/contest/1252/problem/A
1252A, Copying Homework
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cout << n - a[i] + 1 << " ";
    }
    return 0;
}
