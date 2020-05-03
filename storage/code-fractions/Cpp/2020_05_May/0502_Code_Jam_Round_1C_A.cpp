#include <iostream>
#include <string>
using namespace std;

int getDistance(const pair<int, int>& a, const pair<int, int>& b) {
    return (abs(a.first-b.first) + abs(a.second+b.second));
}

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int x, y;
        cin >> x >> y;
        string m;
        cin >> m;

        // Positions of me and Pepurr
        pair<int, int> me(0, 0);
        pair<int, int> pepurr(x, y);

        // Move Pepurr and calculate the distance each step
        int ans = -1;
        for (int i = 0; i < m.size(); i++) {
            // Move Pepurr
            switch(m[i]) {
            case 'N':
                pepurr.second++;
                break;
            case 'S':
                pepurr.second--;
                break;
            case 'E':
                pepurr.first++;
                break;
            case 'W':
                pepurr.first--;
            default:
                break;
            }
            // Calculate distance
            int dist = getDistance(pepurr, me);
            if (dist <= (i+1)) {
                // Possible on step i
                ans = i;
                break;
            }
        }

        // Print answer
        cout << "Case #" << tc+1 << ": ";
        if (ans == -1) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            cout << ans+1 << endl;
        }
    }
    return 0;
}