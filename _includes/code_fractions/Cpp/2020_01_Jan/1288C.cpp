#include <iostream>
using namespace std;
long long ncr(const int& n, const int& r) {
    if (n < r) {
        return 0;
    }
    int** DP = new int*[n+1];
    for (int i = 0; i <= n; i++) {
        DP[i] = new int[r+1];
        DP[i][0] = 1;
    }
    for (int i = 0; i <= r; i++) {
        DP[i][i] = 1;
    }
    for (int i = 1; i <= r; i++) {
        for (int j = i+1; j <= n-r+i; j++) {
            DP[j][i] = (DP[j-1][i] + DP[j-1][i-1]) % 1000000007;
        }
    }
    return DP[n][r];
}
int main() {
    int n, m;
    cin >> n >> m;

    cout << ncr(2*m+n-1, 2*m) << endl;

    return 0;
}
