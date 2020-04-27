/*
This code is an accepted solution to:
https://codeforces.com/contest/1313/problem/C1
During a 2-hour contest : Codeforces Round #622 (Div. 2)
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    long long result_max = 0;
    int result_ind = 0;
    for (int middle = 0; middle < n; middle++) {
        long long result = m[middle];
        int tracker_high = m[middle];
        for (int i = middle-1; i >= 0; i--) {
            tracker_high = min(tracker_high, m[i]);
            result += tracker_high;
        }
        tracker_high = m[middle];
        for (int i = middle+1; i < n; i++) {
            tracker_high = min(tracker_high, m[i]);
            result += tracker_high;
        }
        if (result > result_max) {
            result_max = result;
            result_ind = middle;
        }
    }
    vector<int> ss(n);
    int tracker_high = m[result_ind];
    ss[result_ind] = m[result_ind];
    for (int i = result_ind-1; i >= 0; i--) {
        tracker_high = min(tracker_high, m[i]);
        ss[i] = tracker_high;
    }
    tracker_high = m[result_ind];
    for (int i = result_ind+1; i < n; i++) {
        tracker_high = min(tracker_high, m[i]);
        ss[i] = tracker_high;
    }
    for (int i = 0; i < n; i++) {
        cout << ss[i] << " ";
    }
    cout << endl;

    return 0;
}
