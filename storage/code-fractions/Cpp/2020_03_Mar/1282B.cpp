/*
This code is an accepted solution to:
https://codeforces.com/problemset/problem/1282/B2 [Hard]
https://codeforces.com/problemset/problem/1282/B1 [Easy]
Tags: dp, greedy, sortings, *1600
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        int n, p, k;
        cin >> n >> p >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        int maxGood = 0;
        for (int without = 0; without < k; without++) {
            int goodCount = 0;
            int money = p;
            bool done = false;
            // Buy goods without the offer
            for (int i = 0; i < without; i++) {
                if (money >= a[i]) {
                    money -= a[i];
                    goodCount++;
                }
                else {
                    done = true;
                    break;
                }
            }
            // Buy good using the offer
            for (int i = without+k-1; i < n; i+=k) {
                if (money >= a[i]) {
                    money -= a[i];
                    goodCount+=k;
                }
                else {
                    break;
                }
            }
            if (maxGood > goodCount) {
                break;
            }
            maxGood = goodCount;
        }
        cout << maxGood << endl;
    }
    return 0;
}
