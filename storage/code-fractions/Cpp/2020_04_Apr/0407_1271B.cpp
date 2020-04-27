/*
This code is an accepted solution to:
https://codeforces.com/contest/1271/problem/B
1271B, Blocks
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> isBlack(n);
    char next;
    for (int i = 0; i < n; i++) {
        cin >> next;
        if (next == 'B') {
            isBlack[i] = true;
        }
        else {
            isBlack[i] = false;
        }
    }

    bool possible = true;

    vector<bool> flip(n, false);
    for (int i = 0; i < n-1; i++) {
        if (!isBlack[i]) {
            flip[i] = !flip[i];
            isBlack[i] = !isBlack[i];
            isBlack[i+1] = !isBlack[i+1];
        }
    }
    if (isBlack[n-1]) {
        // done
    }
    else if ((n-1)%2 == 1) {
        possible = false;
    }
    else {
        for (int i = 0; i < n-1; i+=2) {
            flip[i] = !flip[i];
        }
    }

    if (!possible) {
        cout << -1 << endl;
    }
    else {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (flip[i]) {
                count++;
            }
        }
        cout << count << endl;
        for (int i = 0; i < n; i++) {
            if (flip[i]) {
                cout << i+1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
