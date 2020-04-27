/*
This code is an accepted solution to:
https://codeforces.com/contest/1316/problem/B
During a 2-hour contest : CodeCraft-20 (Div. 2)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

/*Trick:
given string "123456789",
k 1: 123456789
k 2: 234567891
k 3: 345678921
k 4: 456789123
k 5: 567894321
k 6: 678912345
k 7: 789654321
k 8: 891234567
k 9: 987654321
*/


string kFlipStr(const string& s, const int& k) {
    // Fast flip!
    // 1. result <- substring from index k-1, length s.size()-k+1.
    // 2. if k odd, result += reverse(substring from 0, length k-1)
    //       k even, result += substring from 0, length k-1
    string result = s.substr(k-1, s.size()-k+1);
    if ((s.size()-k) % 2 == 1) {
        result += s.substr(0, k-1);
    }
    else {
        string sub = s.substr(0, k-1);
        reverse(sub.begin(), sub.end());
        result += sub;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        //1. get the 'smallest' starting points. (in queue.)
        //2. for each starting points, generate strings.
        //3. compare and get the lexicographically smallest (while k smaller)
        char smallest = s[0];
        queue<int> smallestIndex;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == smallest) {
                smallestIndex.push(i+1);
            }
            else if (s[i] < smallest) {
                smallest = s[i];
                queue<int>().swap(smallestIndex);   //clear queue
                smallestIndex.push(i+1);
            }
        }
        // now possible (k+1)'s are inside smallestIndex. (careful for +1!)
        int bestK = smallestIndex.front();
        string bestStr = kFlipStr(s, bestK);
        smallestIndex.pop();
        while (!smallestIndex.empty()) {
            int nextK = smallestIndex.front();
            string nextStr = kFlipStr(s, nextK);
            smallestIndex.pop();
            if (nextStr < bestStr) {
                bestK = nextK;
                bestStr = nextStr;
            }
        }
        cout << bestStr << endl;
        cout << bestK << endl;
    }
    return 0;
}
