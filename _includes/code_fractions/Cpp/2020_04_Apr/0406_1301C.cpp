/*
This code is an accepted solution to:
https://codeforces.com/problemset/problem/1301/C
1301C, Ayoub's function
*/

#include <iostream>
using namespace std;

long long num_substr(const long long& len) {
    return len*(len+1)/2;
}

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        long long n, m;
        cin >> n >> m;

        long long result = num_substr(n);
        if (m == n) {
            // Boundary case: no subtraction
        }
        else if (m == 0) {
            // Boundary case: 0 substring
            result = 0;
        }
        else if (m < n/2) {
            int remainder = (n-m)%(m+1);
            int chunksize = (n-m)/(m+1);
            result -= (m+1-remainder)*num_substr(chunksize);
            if (remainder > 0) {
                result -= remainder*num_substr(chunksize+1);
            }
        }
        else {
            result -= (n-m);
        }

        cout << result << endl;
    }
    return 0;
}
