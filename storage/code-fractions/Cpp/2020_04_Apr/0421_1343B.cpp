#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        // Idea:
        // first half: 2 4  6 10  12 14...
        // second half: 1 5  7 9  11 15...
        // hence, n has to be divisiblea by 4 for this to be possible.
        if (n%4 != 0) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            for (int i = 0; i < n/2; i++) {
                if (i%4 == 0) {
                    cout << (i/2*5) + 2 << " ";
                }
                else if (i%4 == 1) {
                    cout << (i/2*5) + 4 << " ";
                }
                else if (i%4 == 2) {
                    cout << (i/2*5) + 1 << " ";
                }
                else if (i%4 == 3) {
                    cout << (i/2*5) + 5 << " ";
                }
            }
            for (int i = 0; i < n/2; i++) {
                if (i%4 == 0) {
                    cout << (i/2*5) + 1 << " ";
                }
                else if (i%4 == 1) {
                    cout << (i/2*5) + 5 << " ";
                }
                else if (i%4 == 2) {
                    cout << (i/2*5) + 2 << " ";
                }
                else if (i%4 == 3) {
                    cout << (i/2*5) + 4 << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}