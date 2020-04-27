#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int startX, startY, left, top, right, bottom;
        cin >> startX >> startY >> left >> bottom >> right >> top;

        bool possible = true;

        // Can move?
        if (a+b > 0 && right-left < 1) {
            possible = false;
        }
        if (c+d > 0 && top-bottom < 1) {
            possible = false;
        }

        // Left
        if (startX - max(a-b, 0) < left) {
            possible = false;
        }
        // Right
        if (startX + max(b-a, 0) > right) {
            possible = false;
        }
        // Bottom
        if (startY - max(c-d, 0) < bottom) {
            possible = false;
        }
        // Top
        if (startY + max(d-c, 0) > top) {
            possible = false;
        }

        if (possible) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
