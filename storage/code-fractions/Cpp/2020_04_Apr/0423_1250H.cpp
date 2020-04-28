#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        vector<int> c(10);
        int min_candles = 0;
        for (int i = 0; i < 10; i++) {
            cin >> c[i];
            if ((min_candles == 0 && c[i] <= c[min_candles]) || c[i] < c[min_candles]) {
                min_candles = i;
            }
        }
        if (c[min_candles] == 0) {
            if (min_candles == 0) {
                cout << 10 << endl;
            }
            else {
                cout << min_candles << endl;
            }
        }
        else if (min_candles == 0) {
            cout << 1;
            for (int i = 0; i < c[min_candles]+1; i++) {
                cout << min_candles;
            }
            cout << endl;
        }
        else {
            for (int i = 0; i < c[min_candles]+1; i++) {
                cout << min_candles;
            }
            cout << endl;
        }
    }
    return 0;
}