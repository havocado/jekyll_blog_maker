#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int max_diff = 0;
        int first, second;
        for (int i = 1; i < n; i++) {
            if (max_diff < abs(a[i]-a[i-1])) {
                max_diff = abs(a[i]-a[i-1]);
                first = i;
                second = i+1;
            }

        }

        if (max_diff > 1) {
            cout << "YES" << endl;
            cout << first << " " << second << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}