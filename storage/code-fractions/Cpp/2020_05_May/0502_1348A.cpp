#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        bitset<31> result(0);
        result[n/2+1] = 1;
        cout << result.to_ulong()-2 << endl;
    }
    return 0;
}
