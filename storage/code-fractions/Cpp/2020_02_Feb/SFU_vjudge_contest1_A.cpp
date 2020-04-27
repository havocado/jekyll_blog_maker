/*
This code is an accepted solution to:
SFU practice contest 1, problem A
Spring 2020
https://vjudge.net/contest/354512
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    cin >> num;
    if (num.size() == 1) {
        cout << num << endl;
    }
    else {
        int b = -1;
        int front_cut = 0;
        int end_cut = num.size();
        int skip_ind = -1;
        bool dot_found = false;

        int i;
        //front_cut, dot_found, skip_ind, b.
        for (i = 0; i < num.size(); i++) {
            if (num[i] == '.') {
                dot_found = true;
                skip_ind = i;
            }
            else if (num[i] == '0') {
                if (dot_found) {
                    b--;
                }
            }
            else {
                front_cut = i;
                break;
            }
        }
        if (!dot_found) {
            //1.643 form. find dot inside.
            for (int k = i; k < num.size(); k++) {
                if (num[k] == '.') {
                    skip_ind = k;
                    dot_found = true;
                    b = k - front_cut-1;
                    break;
                }
            }
        }
        //setting end_cut.
        for (int k = num.size()-1; k >= front_cut; k--) {
            if (num[k] != '0' && num[k] != '.') {
                end_cut = k+1;
                break;
            }
        }
        //dot doesn't exist inside.
        if (!dot_found) {
            b = num.size() - front_cut - 1;
        }

        // debug
//         cout << "b: " << b << endl
//             << "front cut: " << front_cut << endl
//             << "end cut: " << end_cut << endl
//             << "dot is found: " << dot_found << endl
//             << "dot position: " << skip_ind << endl;


        //printing step
        i = front_cut;
        cout << num[front_cut];
        if (end_cut - front_cut > 1) {
            cout << ".";
        }
        i++;

        for (; i < end_cut; i++) {
            if (i == skip_ind) {
                continue;
            }
            cout << num[i];
        }
        if (b != 0) {
            cout << "E" << b << endl;
        }

    }

    return 0;
}
