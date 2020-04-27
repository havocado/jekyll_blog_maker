/*
This code is an accepted solution to:
https://codeforces.com/contest/122/problem/A
*/
#include <iostream>
using namespace std;

bool helper(const int& n, const int& k) {
    if (k > 1000) {
        return false;
    }
    // Base case
    if (k > n) {
        return false;
    }
    else if (n % k == 0) {
        return true;
    }

    // Recursive case
    bool lucky = (helper(n, k*10 + 4) || helper(n, k*10 + 7));
    return lucky;
}

int main() {
    int n;
    cin >> n;
    bool lucky = (helper(n, 4) || helper(n, 7));
    if (lucky) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
