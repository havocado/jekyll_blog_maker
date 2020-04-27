/*
This code is used as a HELPER for checking the pattern for problem:
https://vjudge.net/contest/354880#problem/C

Code is not optimized for speed.
*/

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<set<int>> results;
set<int> done;

void recurse_generate(const long long& prev, const int& step) {
    if (prev <= 0 || prev >= INT_MAX) {
        return;
    }
    if (step > 10) {
        return;
    }
    results[step].insert(prev);

    recurse_generate(prev-1, step+1);
    recurse_generate(prev+1, step+1);
    recurse_generate(prev*2, step+1);
}
string print_binary(const long long& num) {
    int n = num;
    string res;
    while (n > 0) {
        if (n%2 == 1) {
            res += '1';
        }
        else {
            res += '0';
        }
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    results.reserve(11);
    set<int> temp;
    for (int i = 0; i < 11; i++) {
        results.push_back(temp);
    }
    recurse_generate(1, 1);
    for (int i = 0; i < 11; i++) {
        cout << "Generate step " << i << endl;

        for (set<int>::iterator it = results[i].begin(); it != results[i].end(); it++) {
            bool already_used = false;
            for (int j = 0; j < i; j++) {
                if (results[j].find(*it) != results[j].end()) {
                    already_used = true;
                    break;
                }
            }
            if (already_used) {
                continue;
            }

            cout << print_binary(*it) << endl;
        }
        cout << endl;
    }
}
