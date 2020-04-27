#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int r, c;
vector<vector<bool>> board;
const int WORST = 257;
int worstFlip = WORST;

void tryNextLines(const vector<bool>& firstLine) {
    int count = 0;
    vector<bool> prevLine(c);
    vector<bool> currentLine(c);
    vector<bool> nextLine(c);
    currentLine = firstLine;

    for (int i = 0; i < r; i++) {
        //counting
        for (int j = 0; j < c; j++) {
            if (currentLine[j]) {
                count++;
            }
        }

        //boundary case: c == 1
        if (c == 1) {
            nextLine[0] = (prevLine[0] != currentLine[0]) != board[i][0];
        }
        else {
            // find next line
            nextLine[0] = (prevLine[0] != (currentLine[0] != currentLine[1]))  != board[i][0];
            for (int j = 1; j < c-1; j++) {
                // nextLine on iff prevLine and currentLine makes board[i][j] true.
                // != is used instead of XOR.
                nextLine[j] = (prevLine[j] != (currentLine[j-1] != (currentLine[j] != currentLine[j+1]))) != board[i][j];
            }
            nextLine[c-1] = (prevLine[c-1] != (currentLine[c-1] != currentLine[c-2]))  != board[i][c-1];
        }
        prevLine = currentLine;
        currentLine = nextLine;
    }

    for (int i = 0; i < c; i++) {
        if (currentLine[i]) {
            return;
        }
    }

    worstFlip = (worstFlip < count) ? worstFlip : count;
}

void tryFirstLine(vector<bool> firstLine, const int& step) {
    if (step == firstLine.size()) {
        tryNextLines(firstLine);
    }
    else {
        tryFirstLine(firstLine, step+1);
        firstLine[step] = true;
        tryFirstLine(firstLine, step+1);
    }
}

int main() {
    // Global int r, c;
    cin >> r >> c;

    while (r != 0) {
        // Global vector<vector<bool>> board(r);
        board.clear();
        board.reserve(r);
        vector<bool> line(c);
        char next;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> next;
                line[j] = (next == 'X');
            }
            board.push_back(line);
        }

        vector<bool> firstLine(c);
        tryFirstLine(firstLine, 0);


        if (worstFlip < WORST) {
            cout << "You have to tap " << worstFlip << " tiles." << endl;
        }
        else {
            cout << "Damaged billboard." << endl;
        }
        worstFlip = WORST;

        cin >> r >> c;
    }


    return 0;
}
