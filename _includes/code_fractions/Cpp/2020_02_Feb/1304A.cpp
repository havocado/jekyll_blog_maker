#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if ((y-x)%(a+b) == 0) {
            cout << (y-x)/(a+b) << endl;
        }
        else {
            cout << -1 << endl;
        }

    }

    return 0;
}
