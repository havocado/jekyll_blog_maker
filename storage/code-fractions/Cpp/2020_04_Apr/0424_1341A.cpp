#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if ((a+b)*n < c-d || (a-b)*n > c+d) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}