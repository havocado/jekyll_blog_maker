#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a = -1;
        int b = -1;
        if ((s[s.size()-1]-'0')%2 == 1) {
            b = s[s.size()-1]-'0';
        }
        int i;
        for (i = 0; i < s.size()-1; i++) {
            if ((s[i]-'0')%2 == 1) {
                a = s[i]-'0';
                break;
            }
        }
        if (a == -1) {
            cout << -1 << endl;
            continue;
        }
        for (i++; i < s.size(); i++) {
            if ((s[i]-'0')%2 == 1) {
                b = s[i]-'0';
                break;
            }
        }
        if (b == -1) {
            cout << -1 << endl;
            continue;
        }
        cout << a << b << endl;
    }
    return 0;

}
