/*
This code is an accepted solution to:
https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74
Problem A: Pattern Matching
During a 2 hours and 30 mintues cotest: 2020 Google Code Jam 1A
*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        bool impossible = false;
        bool without_asterisk_found = false;
        string without_asterisk;

        // Setting up inputs
        vector<string> patterns(n);
        vector<string> front_parts;
        vector<string> back_parts;
        vector<string> middle_parts;
        for (int i = 0; i < n; i++) {
            cin >> patterns[i];

            int front_end = -1;
            int back_start = patterns[i].size();

            bool asterisk_appeared = false;
            // Getting front part
            for (int j = 0; j < patterns[i].size() && !impossible; j++) {
                if (patterns[i][j] == '*') {
                    asterisk_appeared = true;
                    if (j > 0) {
                        front_parts.push_back(patterns[i].substr(0, j));
                        front_end = j;
                    }
                    break;
                }
            }
            // Boundary case: String without *
            if (!asterisk_appeared) {
                if (without_asterisk_found
                    && without_asterisk != patterns[i]) {
                    impossible = true;
                }
                without_asterisk_found = true;
                without_asterisk = patterns[i];
            }
            else {
                for (int j = patterns[i].size()-1; j >= 0; j--) {
                    if (patterns[i][j] == '*') {
                        if (j < patterns[i].size()-1) {
                            back_parts.push_back(patterns[i].substr(j+1, patterns[i].size()-j-1));
                            back_start = j;
                        }
                        break;
                    }
                }
            }

            middle_parts.push_back(patterns[i].substr(front_end+1, back_start-front_end-1));

        }

        // Boundary case: String without asterisk exists
        // : Match every front, back and check if they match.
        if (!impossible && without_asterisk_found) {
            for (int i = 0; i < front_parts.size(); i++) {
                for (int j = 0; j < front_parts[i].size(); j++) {
                    if (front_parts[i][j] != without_asterisk[j]) {
                        impossible = true;
                        break;
                    }
                }
                if (impossible) {
                    break;
                }
            }
            for (int i = 0; i < back_parts.size(); i++) {
                int start_pos = without_asterisk.size()-back_parts[i].size();
                for (int j = 0; j < back_parts[i].size(); j++) {
                    if (back_parts[i][j] != without_asterisk[start_pos+j]) {
                        impossible = true;
                        break;
                    }
                }
                if (impossible) {
                    break;
                }
            }
            cout << "Case #" << tc+1 << ": " << without_asterisk << endl;
        }
        // Matching front / back strings.
        // When done, match the middles by simply concatenating.
        else if (!impossible) {
            string front;
            int longest_front_ind = 0;
            for (int i = 0; i < front_parts.size(); i++) {
                if (front_parts[i].size() > front_parts[longest_front_ind].size()) {
                    longest_front_ind = i;
                }
            }
            if (front_parts.size() > 0) {
                front = front_parts[longest_front_ind];
                for (int i = 0; i < front_parts.size(); i++) {
                    for (int j = 0; j < front_parts[i].size(); j++) {
                        if (front_parts[i][j] != front[j]) {
                            impossible = true;
                            break;
                        }
                    }

                }
            }

            string back;
            int longest_back_ind = 0;
            if (!impossible) {
                for (int i = 0; i < back_parts.size(); i++) {
                    if (back_parts[i].size() > back_parts[longest_back_ind].size()) {
                        longest_back_ind = i;
                    }
                }
                if (back_parts.size() > 0) {
                    back = back_parts[longest_back_ind];
                    for (int i = 0; i < back_parts.size(); i++) {
                        int start_pos = back.size()-back_parts[i].size();
                        for (int j = 0; j < back_parts[i].size(); j++) {
                            if (back_parts[i][j] != back[start_pos+j]) {
                                impossible = true;
                                break;
                            }
                        }
                    }
                }
            }


            if (!impossible) {
                cout << "Case #" << tc+1 << ": ";
                cout << front;
                for (int i = 0; i < middle_parts.size(); i++) {
                    for (int j = 0; j < middle_parts[i].size(); j++) {
                        if (middle_parts[i][j] != '*') {
                            cout << middle_parts[i][j];
                        }
                    }
                }
                cout << back << endl;
            }


        }

        if (impossible) {
            cout << "Case #" << tc+1 << ": *" << endl;
        }




    }
    return 0;
}
