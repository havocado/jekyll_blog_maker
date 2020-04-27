/*
This code is an accepted solution to:
https://codeforces.com/contest/1328/problem/D
During a 2-hour contest : Codeforces Round 629
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        vector<int> types(n);
        for (int i = 0; i < n; i++) {
            cin >> types[i];
        }
        vector<int> colors(n);
        int maxColor = 1;
        colors[0] = 1;
        for (int i = 1; i < n-1; i++) {
            if (types[i-1] != types[i]
                && colors[i-1] == 1) {
                colors[i] = 2;
                maxColor = 2;
            }
            else {
                colors[i] = 1;
            }
        }
        // last one (next to first)
        // Spaghetti but not going to fix it!
        colors[n-1] = 1;
        if (types[n-1] != types[0]) {
            // Avoid the first one
            if (types[n-2] != types[n-1]) {
                // Avoid both
                if (colors[n-2] == 2) {
                    colors[n-1] = 3;
                    maxColor = 3;
                    // Edge case: This is not optimal
                    vector<int> anotherWay = colors;
                    anotherWay[n-1] = 2;
                    for (int j = n-2; j >= 0; j--) {
                        if (types[j+1] != types[j]) {
                            anotherWay[j] = 3 - anotherWay[j+1];
                        }
                        else {
                            break;
                        }
                    }
                    if (anotherWay[0] == 1) {
                        colors = anotherWay;
                        maxColor = 2;
                    }
                }
                else {  //(colors[n-2] == 1)
                    colors[n-1] = 2;
                    maxColor = 2;
                }
            }
            else {
                // Avoid only the first one
                colors[n-1] = 3 - colors[0];
                maxColor = max(maxColor, colors[n-1]);
            }
        }
        else if (types[n-1] != types[n-2]) {
            // Avoid only the previous one
            colors[n-1] = 3 - colors[n-2];
            maxColor = max(maxColor, colors[n-1]);
        }
        else {
            colors[n-1] = 1;
        }

        cout << maxColor << endl;
        for (int i = 0; i < n; i++) {
            cout << colors[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
