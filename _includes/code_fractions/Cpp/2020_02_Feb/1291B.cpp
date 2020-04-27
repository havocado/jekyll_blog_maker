#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int maxLeft = n-1;
        //increase
        for (int i = 0; i < n; i++) {
            if (a[i] < i) {
                maxLeft = i-1;
                break;
            }
        }
        int maxRight = 0;
        for (int i = n-1; i >= 0; i--) {
            if (a[i] < n-i-1) {
                maxRight = i+1;
                break;
            }
        }
        if (maxRight - maxLeft > 0) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
