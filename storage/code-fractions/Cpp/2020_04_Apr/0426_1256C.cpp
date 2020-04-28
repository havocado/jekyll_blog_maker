#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> c(m);
    int total_platform_length = 0;
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        total_platform_length += c[i];
    }

    bool possible = true;
    int total_blanks;
    if ((m+1)*(d-1) < n - total_platform_length) {
        possible = false;
    }
    else {
        total_blanks = n - total_platform_length;
    }

    if (possible) {
        cout << "Yes" << endl;
        // Printing blanks and platforms
        for (int i = 0; i < m; i++) {
            // Blanks
            for (int j = 0; j < total_blanks/(m+1); j++) {
                cout << 0 << " ";
            }
            if (i < total_blanks%(m+1)) {
                cout << 0 << " ";
            }
            // Platforms
            for (int j = 0; j < c[i]; j++) {
                cout << i+1 << " ";
            }
        }
        // Last blank
        for (int j = 0; j < total_blanks/(m+1); j++) {
            cout << 0 << " ";
        }
        cout << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}