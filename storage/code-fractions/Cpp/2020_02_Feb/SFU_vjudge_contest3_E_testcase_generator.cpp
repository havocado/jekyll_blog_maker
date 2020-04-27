/*
This code is a testcase generator to check where the runtime error is happening.
Code is not optimized.
*/
#include <iostream>
#include <ctime>
using namespace std;

const N = 30;

int main() {
    srand(time(NULL));
    for (int t = 0; t < N; t++) {
        int r, c;
        r = rand() % 16 + 1;
        c = rand() % 16 + 1;
        cout << r << " " << c << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (rand()%2 == 0) {
                    cout << "X";
                }
                else {
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "0 0" << endl;
    return 0;
}
