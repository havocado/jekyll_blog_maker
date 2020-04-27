/*
This code is an accepted solution to:
https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
Problem A: Vestigium (7 points)
During 2020 Google Code Jam Qualification Round (27 hours)
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        // Setting up input
        vector<vector<int>> m(n);
        vector<vector<pair<int, int>>> positions_asz(n);
        for (int i = 0; i < n; i++) {
            vector<int> row(n);
            for (int j = 0; j < n; j++) {
                cin >> row[j];
                positions_asz[row[j]-1].push_back(pair<int, int>(i+1, j+1));
            }
            m[i] = row;
        }


        // Calculating trace
        int trace = 0;
        for (int i = 0; i < n; i++) {
            trace += m[i][i];
        }

        set<pair<int, int>> duplicate_rows;
        set<pair<int, int>> duplicate_cols;

        // Getting duplicate rows / cols
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < positions_asz[i].size(); j++) {
                for (int k = j+1; k < positions_asz[i].size(); k++) {
                    if (positions_asz[i][j].first == positions_asz[i][k].first) {
                        duplicate_rows.insert(pair<int, int>(positions_asz[i][j].first, positions_asz[i][k].first));
                    }
                    if (positions_asz[i][j].second == positions_asz[i][k].second) {
                        duplicate_cols.insert(pair<int, int>(positions_asz[i][j].second, positions_asz[i][k].second));
                    }
                }
            }
        }

        // Printing results
        cout << "Case #" << tc+1 << ": "
            << trace << " " << duplicate_rows.size() << " "
            << duplicate_cols.size() << endl;

    }


    return 0;
}
