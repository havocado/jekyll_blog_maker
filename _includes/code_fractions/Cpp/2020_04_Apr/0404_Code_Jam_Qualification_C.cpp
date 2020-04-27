/*
This code is an accepted solution to:
https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f
Problem C: Parenting Partnering Returns (7+12 points)
During 2020 Google Code Jam Qualification Round (27 hours)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        // Setting up input
        // <<start, end>, index>
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first.first >> a[i].first.second;
            a[i].second = i;
        }

        // Sort the input
        vector<pair<pair<int, int>, int>> as = a;
        sort(as.begin(), as.end());

        int C_ended = 0, J_ended = 0;
        bool impossible = false;
        vector<char> result(n);
        for (int i = 0; i < n; i++) {
            if (as[i].first.first >= C_ended) {
                // Cameron gets it
                result[as[i].second] = 'C';
                C_ended = as[i].first.second;
            }
            else if (as[i].first.first >= J_ended) {
                // Jamie gets it
                result[as[i].second] = 'J';
                J_ended = as[i].first.second;
            }
            else {
                // Impossible
                impossible = true;
                break;
            }
        }

        // Print result
        cout << "Case #" << tc+1 << ": ";
        if (impossible) {
            cout << "IMPOSSIBLE";
        }
        else {
            for (int i = 0; i < n; i++) {
                cout << result[i];
            }
        }
        cout << endl;

    }
    return 0;
}
