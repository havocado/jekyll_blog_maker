/*
This code is an accepted during contest / hacked (counterexample given later)
solution to:
https://codeforces.com/contest/1311/problem/D
During a 2-hour contest : Codeforces Round #622 (Div. 2)

**This code was written in a rush**
*/

#include <iostream>
#include <cmath>
using namespace std;

int NUM_LIMIT = 10000;
int result = INT_MAX;
int res_a, res_b, res_c;

int main() {
    int num_test;
    cin >> num_test;
    for (int testcase = 0; testcase < num_test; testcase++) {
        int a, b, c;
        cin >> a >> b >> c;

        //case: a, b both increase
        int new_a = a, new_b, new_c;
        while (new_a <= NUM_LIMIT && new_a-a <= result) {
            new_b = (ceil(double(b)/new_a))*new_a;
            while (new_b > 0 && new_b <= NUM_LIMIT) {
                new_c = (ceil(double(c)/new_b))*new_b;
                if (abs(new_a-a)+abs(new_b-b) > result) {
                    break;
                }
                if (new_c > 0 && new_c <= NUM_LIMIT) {
                    if (abs(new_a-a) + abs(new_b-b) + abs(new_c-c) < result) {
                        result = abs(new_a-a) + abs(new_b-b) + abs(new_c-c);
                        res_a = new_a;
                        res_b = new_b;
                        res_c = new_c;
                    }
                }
                new_c = (floor(double(c)/new_b))*new_b;
                if (new_c > 0 && new_c <= NUM_LIMIT) {
                    if (abs(new_a-a) + abs(new_b-b) + abs(new_c-c) < result) {
                        result = abs(new_a-a) + abs(new_b-b) + abs(new_c-c);
                        res_a = new_a;
                        res_b = new_b;
                        res_c = new_c;
                    }
                }
                new_b += new_a;
            }
            new_a++;
        }

        //case: a increase, b decrease
        new_a = a;
        while (new_a <= NUM_LIMIT && new_a-a <= result) {
            new_b = (floor(double(b)/new_a))*new_a;
            while (new_b > 0 && new_b <= NUM_LIMIT) {
                new_c = (ceil(double(c)/new_b))*new_b;
                if (abs(new_a-a)+abs(new_b-b) > result) {
                    break;
                }
                if (new_c > 0 && new_c <= NUM_LIMIT) {
                    if (abs(new_a-a) + abs(new_b-b) + abs(new_c-c) < result) {
                        result = abs(new_a-a) + abs(new_b-b) + abs(new_c-c);
                        res_a = new_a;
                        res_b = new_b;
                        res_c = new_c;
                    }
                }
                new_c = (floor(double(c)/new_b))*new_b;
                if (new_c > 0 && new_c <= NUM_LIMIT) {
                    if (abs(new_a-a) + abs(new_b-b) + abs(new_c-c) < result) {
                        result = abs(new_a-a) + abs(new_b-b) + abs(new_c-c);
                        res_a = new_a;
                        res_b = new_b;
                        res_c = new_c;
                    }
                }
                new_b -= new_a;
            }
            new_a++;
        }

        //case: a decrease, b increase
        new_a = a;
        while (new_a > 0 && abs(new_a-a) <= result) {
            new_b = (ceil(double(b)/new_a))*new_a;
            while (new_b > 0 && new_b <= NUM_LIMIT) {
                new_c = (ceil(double(c)/new_b))*new_b;
                if (abs(new_a-a)+abs(new_b-b) > result) {
                    break;
                }
                if (new_c > 0 && new_c <= NUM_LIMIT) {
                    if (abs(new_a-a) + abs(new_b-b) + abs(new_c-c) < result) {
                        result = abs(new_a-a) + abs(new_b-b) + abs(new_c-c);
                        res_a = new_a;
                        res_b = new_b;
                        res_c = new_c;
                    }
                }
                new_c = (floor(double(c)/new_b))*new_b;
                if (new_c > 0 && new_c <= NUM_LIMIT) {
                    if (abs(new_a-a) + abs(new_b-b) + abs(new_c-c) < result) {
                        result = abs(new_a-a) + abs(new_b-b) + abs(new_c-c);
                        res_a = new_a;
                        res_b = new_b;
                        res_c = new_c;
                    }
                }
                new_b += new_a;
            }
            new_a--;
        }

        //case: a, b both decrease
        new_a = a;
        while (new_a > 0 && new_a-a <= result) {
            new_b = (floor(double(b)/new_a))*new_a;
            while (new_b > 0 && new_b <= NUM_LIMIT) {
                new_c = (ceil(double(c)/new_b))*new_b;
                if (abs(new_a-a)+abs(new_b-b) > result) {
                    break;
                }
                if (new_c > 0 && new_c <= NUM_LIMIT) {
                    // if (testcase == 2) cout << "trying " << new_a << ", " << new_b << ", " << new_c << endl;
                    if (abs(new_a-a) + abs(new_b-b) + abs(new_c-c) < result) {
                        result = abs(new_a-a) + abs(new_b-b) + abs(new_c-c);
                        res_a = new_a;
                        res_b = new_b;
                        res_c = new_c;
                        // cout << "result pair " << new_a << ", " << new_b << ", " << new_c << endl;
                    }
                }
                new_c = (floor(double(c)/new_b))*new_b;
                if (new_c > 0 && new_c <= NUM_LIMIT) {
                    // if (testcase == 2) cout << "trying " << new_a << ", " << new_b << ", " << new_c << endl;
                    if (abs(new_a-a) + abs(new_b-b) + abs(new_c-c) < result) {
                        result = abs(new_a-a) + abs(new_b-b) + abs(new_c-c);
                        res_a = new_a;
                        res_b = new_b;
                        res_c = new_c;
                        // cout << "result pair " << new_a << ", " << new_b << ", " << new_c << endl;
                    }
                }
                new_b -= new_a;
            }
            new_a--;
        }

        cout << result << endl;
        cout << res_a << " " << res_b << " " << res_c << endl;
        result = INT_MAX;
    }
    return 0;
}
