/*
This code is an accepted solution to:
https://codeforces.com/problemset/problem/1278/C
Tags: data structures, dp, greedy, implementation, *1600
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        int n;
        cin >> n;
        vector<int> jams(2*n);
        // Save as: Red 1, Blue -1.
        // Setting up input
        int next;
        int num_Red = 0;
        int num_Blue = 0;
        for (int i = 0; i < 2*n; i++) {
            cin >> next;
            if (next == 1) {
                jams[i] = 1;
                num_Red++;
            }
            else {
                jams[i] = -1;
                num_Blue++;
            }
        }

        // Goal to reach. (DP without saving values)
        int diffGoal = num_Red - num_Blue;

        // Setting up vectors of (Red - Blue), each left and right.
        vector<int> leftSum(n+1);
        vector<int> rightSum(n+1);
        leftSum[0] = 0;
        for (int i = 1; i <= n; i++) {
            leftSum[i] = leftSum[i-1] + jams[n-i];
        }
        rightSum[0] = 0;
        for (int i = 1; i <= n; i++) {
            rightSum[i] = rightSum[i-1] + jams[n+i-1];
        }

        // Finding where left + right = diffGoal
        // Prune: Answer can only be diffGoal + 2*i (i: integer)
        bool found = false;
        int result = 0;
        for (int eatNum = diffGoal; eatNum <= 2*n; eatNum+=2) {
            for (int i = max(0, eatNum-n); i <= eatNum && i <= n; i++) {
                if (leftSum[i] + rightSum[eatNum-i] == diffGoal) {
                    result = eatNum;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        cout << result << endl;
    }
    return 0;
}
