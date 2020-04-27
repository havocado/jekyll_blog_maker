/*
This code is an accepted solution to:
https://codeforces.com/problemset/problem/1268/A
Tags: constructive algorithms, greedy, implementation, strings, *1700
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;

    // first K digits
    string firstK = a.substr(0, k);

    // Simple form: use first K digits
    string simpleForm;
    for (int i = 0; i < n; i++) {
        simpleForm += firstK[i%k];
    }

    cout << n << endl;
    if (simpleForm >= a) {
        cout << simpleForm << endl;
    }
    else {
        firstK[k-1]++;
        for (int i = 0; i < k; i++) {
            if (firstK[k-i-1] > '9') {
                firstK[k-i-1] = '0';
                firstK[k-i-2]++;
            }
            else {
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << firstK[i%k];
        }
        cout << endl;
    }
    return 0;
}
