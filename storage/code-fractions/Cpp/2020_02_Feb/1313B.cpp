/*
This code is an accepted solution to:
https://codeforces.com/contest/1313/problem/B
During a 2-hour contest : Codeforces Round #622 (Div. 2)
*/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        int n, x, y;
        cin >> n >> x >> y;
        int sum = x+y;
        int rank_max, rank_min;
        if (n >= sum) {
            // cout << "Min: case A" << endl;
            rank_min = 1;
        }
        else {
            // cout << "Min: case B" << endl;
            rank_min = sum-n+1;
        }
        if (n >= sum - 1) {
            // cout << "Max: case A" << endl;
            rank_max = sum-1;
        }
        else {
            // cout << "Max: case B" << endl;
            rank_max = n;
        }
        if (rank_min > n) {
            rank_min = n;
        }

        cout << rank_min << " " << rank_max << endl;
    }
    return 0;
}
