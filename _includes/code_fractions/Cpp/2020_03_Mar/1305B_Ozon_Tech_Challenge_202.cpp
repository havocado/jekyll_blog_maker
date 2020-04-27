/*
This code is an accepted solution to:
https://codeforces.com/contest/1305/problem/B
During a 2-hour contest : Ozon Tech Challenge 2020
*/
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Counter {
public:
    int openUntilHere;
    int closeUntilHere;
    int openAfterHere;
    int closeAfterHere;
    Counter() : openUntilHere(0), closeUntilHere(0),
        openAfterHere(0), closeAfterHere(0) { }
};

int main() {
    string s;
    cin >> s;

    // For O(1) access for counting cumulative open/close
    vector<Counter> counter(s.size());
    // Forward setup
    if (s[0] == '(') {
        counter[0].openUntilHere = 1;
    }
    else {
        counter[0].closeUntilHere = 1;
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '(') {
            counter[i].openUntilHere = counter[i-1].openUntilHere + 1;
            counter[i].closeUntilHere = counter[i-1].closeUntilHere;
        }
        else {
            counter[i].openUntilHere = counter[i-1].openUntilHere;
            counter[i].closeUntilHere = counter[i-1].closeUntilHere + 1;
        }
    }
    // Backward setup
    for (int i = s.size()-2; i >= 0; i--) {
        if (s[i+1] == '(') {
            counter[i].openAfterHere = counter[i+1].openAfterHere + 1;
            counter[i].closeAfterHere = counter[i+1].closeAfterHere;
        }
        else {
            counter[i].openAfterHere = counter[i+1].openAfterHere;
            counter[i].closeAfterHere = counter[i+1].closeAfterHere + 1;
        }
    }

    // Finding the optimal cut-point
    int maxInd = -1;
    int maxCurrent = 0;
    for (int i = 0; i < s.size(); i++) {
        int current = min(counter[i].openUntilHere, counter[i].closeAfterHere);
        if (current > maxCurrent) {
            maxInd = i;
            maxCurrent = current;
        }
    }
    // cout << maxInd << endl;

    if (maxInd == -1) {
        // no operation possible
        cout << 0 << endl;
    }
    else {
        cout << 1 << endl;
        cout << maxCurrent*2 << endl;
        int printCount = 0;
        for (int i = 0; printCount < maxCurrent; i++) {
            if (s[i] == '(') {
                cout << i+1 << " ";
                printCount++;
            }
        }
        printCount = 0;
        stack<int> printHelper;
        for (int i = s.size()-1; printCount < maxCurrent; i--) {
            if (s[i] == ')') {
                printHelper.push(i+1);
                printCount++;
            }
        }
        while (!printHelper.empty()) {
            cout << printHelper.top() << " ";
            printHelper.pop();
        }
        cout << endl;
    }

    return 0;
}
