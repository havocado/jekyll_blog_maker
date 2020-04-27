/*
This code is an accepted solution to:
https://codeforces.com/contest/1255/problem/C
1255C, League of Leesins
*/
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> get_next_two(const int& prev1, const int& prev2, const vector<int>& related) {
    int first = -1;
    int first_occurrence = 0;
    int second = -1;
    int second_occurrence = 0;
    for (int i = 0; i < related.size(); i++) {
        if (related[i] == prev1 || related[i] == prev2) {
            continue;
        }
        else if (first_occurrence == 0) {
            first = related[i];
            first_occurrence++;
        }
        else if (related[i] == first) {
            first_occurrence++;
        }
        else if (second_occurrence == 0) {
            second = related[i];
            second_occurrence++;
        }
        else {
            second_occurrence++;
        }
    }
    if (first_occurrence > second_occurrence) {
        return pair<int, int>(first, second);
    }
    else {
        return pair<int, int>(second, first);
    }
}

void set_next_two_element(const int& done_ind, vector<int>& result, const vector<vector<int>>& related) {
    if (done_ind == result.size()-1) {
        return;
    }
    else if (done_ind == result.size()-2) {
        // Only one left
        pair<int, int> next_one;
        if (done_ind > 1) {
            next_one = get_next_two(result[done_ind-1], result[done_ind-2], related[result[done_ind]]);
        }
        else {
            next_one = get_next_two(result[done_ind-1], -1, related[result[done_ind]]);
        }
        result[done_ind+1] = next_one.first;
    }
    else {
        // set two more
        pair<int, int> next_two;
        if (done_ind > 1) {
            next_two = get_next_two(result[done_ind-1], result[done_ind-2], related[result[done_ind]]);
        }
        else {
            next_two = get_next_two(result[done_ind-1], -1, related[result[done_ind]]);
        }

        result[done_ind+1] = next_two.first;
        result[done_ind+2] = next_two.second;
    }
}

int main() {
    int n;
    cin >> n;

    // Containers
    vector<vector<int>> related(n);

    // Setting up input
    for (int i = 0; i < n-2; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        // Make them start from 0
        a--; b--; c--;

        // Save into containers
        related[a].push_back(b);
        related[a].push_back(c);
        related[b].push_back(a);
        related[b].push_back(c);
        related[c].push_back(a);
        related[c].push_back(b);
    }

    vector<int> result(n);

    // Finding a first element (smaller of two)
    for (int i = 0; i < n; i++) {
        if (related[i].size() == 2) {
            result[0] = i;
            break;
        }
    }

    // Finding the second element
    if (related[related[result[0]][0]].size() == 4) {
        result[1] = related[result[0]][0];
    }
    else {
        result[1] = related[result[0]][1];
    }

    for (int i = 0; i < (n+1)/2-1; i++) {
        set_next_two_element(2*i+1, result, related);
    }

    for (int i = 0; i < n; i++) {
        cout << result[i]+1 << " ";
    }

    return 0;
}
