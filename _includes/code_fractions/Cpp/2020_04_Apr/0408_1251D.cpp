/*
This code is an accepted solution to:
https://codeforces.com/contest/1251/problem/D
1251D, Salary Changing
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isValid(const long long& median, const vector<pair<long long, long long>>& ranges, const long long& s) {
    // check if a median works
    // Select half with lowest 'low'
    // that has 'high' at least 'median'.
    // (if can't be selected, return false.)
    // Sum of the whole. Compare with s.

    long long select_count = 0;
    long long sum = 0;
    for (int i = 0; i < ranges.size(); i++) {
        if (select_count < (ranges.size()+1)/2 && ranges[i].second >= median) {
            sum += max(ranges[i].first, median);
            select_count++;
        }
        else {
            sum += ranges[i].first;
        }
    }
    if (select_count < (ranges.size()+1)/2) {
        return false;
    }
    else {
        return (sum <= s);
    }
}

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        long long n, s;
        cin >> n >> s;

        // Setting up input
        vector<pair<long long, long long>> ranges(n);
        long long min_low = s;
        long long max_high = 0;
        for (int i = 0; i < n; i++) {
            cin >> ranges[i].first >> ranges[i].second;
            min_low = min(ranges[i].first, min_low);
            max_high = max(ranges[i].second, max_high);
        }
        sort(ranges.begin(), ranges.end(), greater<pair<long long, long long>>());

        long long low = min_low;
        long long high = max_high;
        long long middle;
        while (low < high) {
            middle = (low+high+1)/2;

            if (isValid(middle, ranges, s)) {
                low = middle;
            }
            else {
                high = middle-1;
            }
        }

        cout << low << endl;
    }

    return 0;
}
