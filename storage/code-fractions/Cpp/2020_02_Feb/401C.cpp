#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m == 1 && n <= 2) {
        if (n == 1) {
            cout << "10" << endl;
        }
        else {
            cout << "010" << endl;
        }
    }
    else if (n < m/2-1+(m%2) || n > m+1) {
        cout << -1 << endl;
    }
    else {
        int len_p;
        if (m%2 == 0){
            len_p = m*3/2 - 1;
        }
        else {
            len_p = (m-1)*3/2 + 1;
        }
        int len_ex = n + m - len_p;
        int ex_count = 0;
        if (ex_count < len_ex) {
            cout << 0;
            ex_count++;
        }
        for (int i = 0; i < len_p; i++) {
            if (i%3 <= 1) {
                if (i%3 == 1 && ex_count < len_ex) {
                    cout << 0;
                    ex_count++;
                }
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        if (ex_count < len_ex) {
            cout << 0;
            ex_count++;
        }
        cout << endl;
    }

    return 0;
}
