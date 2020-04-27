/*
This code is an accepted solution to:
https://codeforces.com/contest/1335/problem/D
Problem D: Anti-Sudoku
During a 2-hour contest: Codeforces Round #634
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        vector<vector<char>> sudoku(9);

        // Filling sudoku from input
        for (int i = 0; i < 9; i++) {
            vector<char> sudoku_line(9);
            for (int j = 0; j < 9; j++) {
                cin >> sudoku_line[j];
            }
            sudoku[i] = sudoku_line;
        }

        // I'm too lazy to explain this.
        // To understand: draw 9*9 sudoku and track what it changes
        for (int i = 0; i < 9; i++) {
            int col = (3*i)%9+i/3;
            sudoku[i][col]++;
            if (sudoku[i][col] > '9') {
                sudoku[i][col] = '1';
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
