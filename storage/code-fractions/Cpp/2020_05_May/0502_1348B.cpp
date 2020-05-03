#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        set<int> distinct_elem;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            distinct_elem.insert(a[i]);
        }

        if (distinct_elem.size() > k) {
            cout << -1 << endl;
        }
        else {
            cout << k*n << endl;
            vector<int> repeated_part(k);
            int i = 0;
            for (set<int>::iterator it = distinct_elem.begin(); it != distinct_elem.end(); it++) {
                repeated_part[i] = *it;
                i++;
            }

            for (; i < k; i++) {
                repeated_part[i] = a[0];
            }
            for (int j = 0; j < n; j++) {
                for (int m = 0; m < k; m++) {
                    cout << repeated_part[m] << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}