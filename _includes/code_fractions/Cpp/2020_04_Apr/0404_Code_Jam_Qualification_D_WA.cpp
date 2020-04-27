/*
This code is NOT an accepted solution to:
Problem D
During 2020 Google Code Jam Qualification Round (27 hours)
*/


#include <iostream>
#include <vector>
using namespace std;

/*
'mirror': two bits that are same from left-right
mirror.first == mirror.second
'couple': two bits that are different from left-right
couple.first != couple.second
1. Read 1~5, b-4~b.
if mirror happened, save it to the pair.
if couple happened, save it to the pair.
2. when q%10 == 1,
if couple found,
check one of the couple. (1 query)
if flipped, (either complement or reverse, not both)
if mirror found,
check one of the mirror. (1 query)
if flipped, (it's complemented)
complement the current.
else, (it's reversed)
reverse the current.
else, (comp.or rev. doesn't matter)
complement the current. (identical with rev.)
else, (both or none)
if mirror found,
check one of the mirror. (1 query)
if flipped, (both comp.and rev.)
comp. and rev. the current.
else (nothing happend)
nothing happens.
else, (no change)
nothing happens.

else (couple not found),
// (all bits are mirrors. no reverse effect.)
check a mirror. (1 query)
if flipped, (it's comp.)
comp. the current.
else (no change)
nothing happens.

*/
void complement_all(vector<int>& current) {
	for (int i = 0; i < current.size(); i++) {
		if (current[i] == 0) {
			current[i] = 1;
		}
		else if (current[i] == 1) {
			current[i] = 0;
		}
	}
}

void reverse_all(vector<int>& current) {
	for (int i = 0; i < current.size() / 2; i++) {
		int temp = current[i];
		current[i] = current[current.size() - i - 1];
		current[current.size() - i - 1] = temp;
	}
}

int main() {
	int t, b;
	cin >> t >> b;
	for (int tc = 0; tc < t; tc++) {
		// careful for index! (starts 0)
		vector<int> current(b, -1);
		int undecided = b;

		bool mirror_is_found = false;
		pair<int, int> mirror;
		bool couple_is_found = false;
		pair<int, int> couple;

		int dist_from_end = 0;
		bool from_left = true;
		for (int q = 1; q <= 150; q++) {
			if (q > 1 && q % 10 == 1) {
				int received;
				// Special case - read comment above
				if (couple_is_found) {
					cout << couple.first + 1 << endl;
					q++;
					cin >> received;
					// A
					if (received != current[couple.first]) {
						if (mirror_is_found) {
							cout << mirror.first + 1 << endl;
							q++;
							cin >> received;
							if (received != current[mirror.first]) {
								complement_all(current);
							}
							else {
								reverse_all(current);
							}
						}
						else {
							complement_all(current);
						}
					}
					// B
					else {
						if (mirror_is_found) {
							cout << mirror.first + 1 << endl;
							q++;
							cin >> received;
							if (received != current[mirror.first]) {
								complement_all(current);
								reverse_all(current);
							}
							else {
								// Nothing happens
							}
						}
						else {
							// Nothing happens
						}
					}

				}
				else {
					cout << mirror.first + 1 << endl;
					q++;
					cin >> received;
					// C
					if (received != current[mirror.first]) {
						complement_all(current);
					}
					else {
						// Nothing happens
					}

				}
			}
			else {
				// Normal case
				// Deciding query
				int query_ind;
				if (from_left) {
					query_ind = dist_from_end + 1;
				}
				else {
					query_ind = b - dist_from_end;
				}

				// Sending query
				cout << query_ind << endl;

				// Receiving result
				int received;
				cin >> received;

				// Saving result and setting mirror/couple.
				current[query_ind - 1] = received;
				undecided--;
				if (!from_left) {
					if (!mirror_is_found && current[dist_from_end]
						== current[b - dist_from_end - 1]) {
						mirror_is_found = true;
						mirror.first = dist_from_end;
						mirror.second = b - dist_from_end - 1;
					}
					else if (!couple_is_found && current[dist_from_end]
						!= current[b - dist_from_end - 1]) {
						couple_is_found = true;
						couple.first = dist_from_end;
						couple.second = b - dist_from_end - 1;
					}
				}

				if (!from_left) {
					dist_from_end++;
				}
				from_left = !from_left;
			}
			if (undecided == 0) {
				break;
			}
		}

		// Done, print result
		for (int i = 0; i < b; i++) {
			cout << current[i];
		}
		cout << endl;

		char judge_result;
		cin >> judge_result;
		if (judge_result == 'N') {
			break;
		}
	}
	return 0;
}
