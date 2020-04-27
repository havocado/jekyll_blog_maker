/*
This code is an accepted solution to:
https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f
Problem B: Nesting depth (5+11 points)
During 2020 Google Code Jam Qualification Round (27 hours)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        string s;
        cin >> s;
        int tracker = '0';
        string result;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > tracker) {
                for (int j = 0; j < s[i]-tracker; j++) {
                    result += "(";
                }
            }
            else if (s[i] < tracker) {
                for (int j = 0; j < tracker-s[i]; j++) {
                    result += ")";
                }
            }
            result += s[i];
            tracker = s[i];
        }
        if (tracker > 0) {
            for (int j = 0; j < tracker-'0'; j++) {
                result += ")";
            }
        }

        cout << "Case #" << tc+1 << ": " << result << endl;
    }
    return 0;
}
