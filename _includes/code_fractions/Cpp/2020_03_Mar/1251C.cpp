/*
This code is an accepted solution to:
https://codeforces.com/problemset/problem/1251/C
Tags: greedy, two pointers, *1500
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        queue<char> odd;
        queue<char> even;

        // setting up input
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i]-'0')%2 == 1) {
                odd.push(s[i]);
            }
            else {
                even.push(s[i]);
            }
        }

        // Using queue to generate result
        string result;
        while (!odd.empty() && !even.empty()) {
            if (odd.front() < even.front()) {
                result += odd.front();
                odd.pop();
            }
            else {
                result += even.front();
                even.pop();
            }
        }
        while (!odd.empty()) {
            result += odd.front();
            odd.pop();
        }
        while (!even.empty()) {
            result += even.front();
            even.pop();
        }

        // Print out result string
        cout << result << endl;

    }
    return 0;
}
