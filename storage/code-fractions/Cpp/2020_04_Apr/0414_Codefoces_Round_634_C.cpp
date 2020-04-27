/*
This code is an accepted solution to:
https://codeforces.com/contest/1335/problem/C
Problem C: Two Teams Composing
During a 2-hour contest: Codeforces Round #634
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        // skills[s] = (# of people with skill s)
        vector<int> skills(n, 0);
        int next;
        for (int i = 0; i < n; i++) {
            cin >> next;
            skills[next-1]++;
        }

        // num_diff_skills, max_same_skills
        // which are possible maximum values of two teams
        int num_diff_skills = 0;
        int max_same_skills = 0;
        for (int i = 0; i < n; i++) {
            if (skills[i] > 0) {
                num_diff_skills++;
                max_same_skills = max(max_same_skills, skills[i]);
            }
        }

        // Result is the smaller of both
        // Boundary case: when the two are same,
        // there is an overlapping student so -1.
        if (num_diff_skills == max_same_skills) {
            cout << num_diff_skills-1 << endl;
        }
        else {
            cout << min(num_diff_skills, max_same_skills) << endl;
        }
    }
    return 0;
}
