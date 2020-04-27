/*
This code is used as a HELPER for checking the formula for problem:
https://vjudge.net/contest/357113#problem/A

Code is not optimized for speed.
*/

#include <iostream>
using namespace std;

int main() {
    // Recursion formula checker
    int num = 1;
    int m = 10000;
    int step = 1;
    int print_amount = 1;
    while (num < m) {
        cout << "step " << step << ": " << endl;
        for (int k = 0; k < print_amount; k++) {
            cout << num++ << " ";
        }
        cout << endl;
        int expected;
        if (step%2 == 0) {
            expected = 2*step + (step/2-1)*(step/2)*6;
        }
        else {
            expected = (step+1)/2 + ((step-1)/2)*((step+1)/2)*3 + (step-1)/2*3
              + ((step-1)/2)*((step-3)/2)*3;
        }
        cout << "Expected end: " << expected << endl;

        if (step%2 == 1) {
            print_amount += 2;
        }
        else {
            print_amount += 4;
        }
        step++;

    }

    return 0;
}
