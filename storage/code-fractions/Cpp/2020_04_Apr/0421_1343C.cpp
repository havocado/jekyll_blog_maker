#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool current_positive = (a[0] > 0);
        long long current_max_pos = LLONG_MIN;
        long long current_max_neg = LLONG_MIN;
        long long result = 0;
        for (int i = 0; i < n; i++) {
            if (current_positive) {
                if (a[i] > 0) {
                    current_max_pos = max(current_max_pos, a[i]);
                }
                else {
                    result += current_max_pos;
                    current_max_neg = a[i];
                    current_positive = false;
                }
            }
            else { // if (current_negative)
                if (a[i] < 0) {
                    current_max_neg = max(current_max_neg, a[i]);
                }
                else {
                    result += current_max_neg;
                    current_max_pos = a[i];
                    current_positive = true;
                }
            }
        }
        if (current_positive) {
            result += current_max_pos;
        }
        else { // if (current_negative)
            result += current_max_neg;
        }

        cout << result << endl;
    }
    return 0;
}
