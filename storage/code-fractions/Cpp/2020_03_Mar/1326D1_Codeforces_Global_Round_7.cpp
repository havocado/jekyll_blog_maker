/*
This code is an accepted solution to:
https://codeforces.com/contest/1326/problem/D1
During a 2-hour contest : Codeforces Global Round 7

**This code was written in a rush**
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        string s;
        cin >> s;
        int left = 0;
        int right = s.size()-1;

        // start crawling from both sides;
        int commonLetters = 0;
        while (s[left] == s[right] && left < right) {
            commonLetters++;
            left++;
            right--;
        }
        // Now 'commonLetters' letters are going to be used.

        // Boundary case
        if (left >= right) {
            cout << s << endl;;
            continue;
        }

        // Try getting extra palindrome from left
        // (finding same character O(n);
        // check palindrome each O(n))
        string left_best = "";
        char start = s[left];
        for (int i = right; i >= left; i--) {
            if (s[i] == start) {
                // check if palindrome works
                int left_checker = left;
                int right_checker = i;
                bool possible = true;
                while (left_checker <= right_checker) {
                    if (s[left_checker] != s[right_checker]) {
                        possible = false;
                        break;
                    }
                    else {
                        left_checker++;
                        right_checker--;
                    }
                }
                if (possible) {
                    left_best = s.substr(left, i-left+1);
                    break;
                }
            }
        }

        string right_best = "";
        start = s[right];
        for (int i = left; i <= right && right-i+1 >= left_best.size(); i++) {
            if (s[i] == start) {
                // check if palindrome works
                int left_checker = i;
                int right_checker = right;
                bool possible = true;
                while (left_checker < right_checker) {
                    if (s[left_checker] != s[right_checker]) {
                        possible = false;
                        break;
                    }
                    else {
                        left_checker++;
                        right_checker--;
                    }
                }
                if (possible) {
                    right_best = s.substr(i, right-i+1);
                    break;
                }
            }
        }

        // common letters
        for (int i = 0; i < commonLetters; i++) {
            cout << s[i];
        }
        if (left_best.size() > right_best.size()) {
            cout << left_best;
        }
        else {
            cout << right_best;
        }
        // common letters
        for (int i = commonLetters-1; i >= 0; i--) {
            cout << s[i];
        }
        cout << endl;


    }
    return 0;
}
