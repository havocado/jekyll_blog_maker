#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, k;
        cin >> n >> k;

        // Setting up input
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Number of peaks in [i, i+k-1]
        vector<bool> is_peak(n, false);
        for (int i = 1; i < n-1; i++) {
            if (a[i] > a[i-1] && a[i] > a[i+1]) {
                is_peak[i] = true;
            }
        }
        vector<int> num_peaks(n, 0);
        int num_peaks_in_last_k = 0;
        int max_num_peaks = 0;
        int left = 0;
        for (int i = 1; i < n; i++) {
            if (is_peak[i-1]) {
                num_peaks_in_last_k++;
            }
            if (i >= k-1 && is_peak[i-k+1]) {
                num_peaks_in_last_k--;
            }
            num_peaks[i] = num_peaks_in_last_k;
            if (i >= k-1 && num_peaks[i] > max_num_peaks) {
                max_num_peaks = num_peaks[i];
                left = i-k+1;
            }
        }

        cout << max_num_peaks+1 << " " << left+1 << endl;

    }
    return 0;
}