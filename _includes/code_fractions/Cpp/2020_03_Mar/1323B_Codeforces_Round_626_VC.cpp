/*
This code is an accepted solution to:
https://codeforces.com/contest/1323/problem/B
During a 2-hour Virtual Contest :
Codeforces Round #626 (Div. 2, based on Moscow Open Olympiad in Informatics)
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    // Break up k
    vector<pair<int, int>> sizes;
    for (int i = 1; i <= sqrt(k); i++) {
        if (k%i == 0) {
            sizes.push_back(pair<int, int>(i, k/i));
            if (i < k/i) {
                sizes.push_back(pair<int, int>(k/i, i));
            }
        }
    }

    vector<pair<int, int>> sideCounter(sizes.size(), pair<int, int>(0, 0));
    // Setting up input
    int counter = 0;
    int next;
    for (int i = 0; i < n; i++) {
        cin >> next;
        if (next == 1) {
            counter++;
            for (int j = 0; j < sizes.size(); j++) {
                if (counter >= sizes[j].first) {
                    sideCounter[j].first++;
                }
            }
        }
        else {
            counter = 0;
        }
    }
    counter = 0;
    for (int i = 0; i < m; i++) {
        cin >> next;
        if (next == 1) {
            counter++;
            for (int j = 0; j < sizes.size(); j++) {
                if (counter >= sizes[j].second) {
                    sideCounter[j].second++;
                }
            }
        }
        else {
            counter = 0;
        }
    }

    // Calculate and print result
    long long result = 0;
    for (int i = 0; i < sizes.size(); i++) {
        result += sideCounter[i].first * sideCounter[i].second;
    }
    cout << result << endl;

    return 0;
}
