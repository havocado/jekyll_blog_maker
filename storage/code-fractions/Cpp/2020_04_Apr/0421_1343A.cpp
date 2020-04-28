#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        // Find if there is a 'b' such that:
        // x*b=n, b is 1111.. form in binary.
        bitset<32> b(3);
        for (int i = 1; i < 32; i++) {
            b[i] = 1;
            if (n%b.to_ulong() == 0) {
                cout << n/b.to_ulong() << endl;
                break;
            }
        }
    }
    return 0;
}