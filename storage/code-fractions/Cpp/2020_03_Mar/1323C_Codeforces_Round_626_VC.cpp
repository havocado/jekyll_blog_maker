/*
This code is an accepted solution to:
https://codeforces.com/contest/1323/problem/C
During a 2-hour Virtual Contest :
Codeforces Round #626 (Div. 2, based on Moscow Open Olympiad in Informatics)
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // check and save validity
    int result = 0;
    vector<bool> isValid(n);
    int open = 0;
    int close = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            open++;
        }
        else {
            close++;
        }

        isValid[i] = (close <= open);
        if (!isValid[i] || (i > 0 && !isValid[i-1])) {
            result++;
        }
    }

    if (open == close) {
        cout << result << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}
