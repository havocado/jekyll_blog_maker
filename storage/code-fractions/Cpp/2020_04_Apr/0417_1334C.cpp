/*
This code is an accepted solution to:
https://codeforces.com/contest/1334/problem/C
1334C, Circle of Monsters
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Calculate for each monsters, needed shots assuming that the previous monster died.
    // Add all of them, and lastly add the minimum bi existing.
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        scanf("%d", &n);
        // cin >> n;
        vector<long long> healths(n);
        vector<long long> explosion(n);
        long long min_explosion = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            // cin >> healths[i] >> explosion[i];
            scanf("%lld%lld", &healths[i], &explosion[i]);
            if (healths[i] < min_explosion) {
                min_explosion = healths[i];
            }
            if (explosion[i] < min_explosion) {
                min_explosion = explosion[i];
            }
        }
        long long num_shots = min_explosion;
        if (healths[0]-explosion[n-1] > 0) {
            num_shots += healths[0]-explosion[n-1];
        }
        for (int i = 1; i < n; i++) {
            if (healths[i]-explosion[i-1] > 0) {
                num_shots += healths[i]-explosion[i-1];
            }
        }

        // cout << num_shots << endl;
        printf("%lld\n", num_shots);
    }
    return 0;
}
