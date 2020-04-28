#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        bool impossible = false;

        int next;
        cin >> next;
        int min_appeared = next;
        int prev;
        for (int i = 1; i < n; i++) {
            prev = next;
            cin >> next;
            if (!impossible) {
                if (next < min_appeared) {
                    min_appeared = next;
                }
                else {
                    if (next != prev+1) {
                        impossible = true;
                    }
                }
            }
        }
        if (impossible) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}