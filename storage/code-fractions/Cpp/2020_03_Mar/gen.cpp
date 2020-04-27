#include <iostream>
using namespace std;

int main() {
	cout << 2500 << endl;
	for (int i = 0; i < 2500; i++) {
		cout << 5000 << endl;
		for (int j = 0; j < 2000; j++) {
			cout << "ba";
		}
		cout << "ca";
		for (int j = 0; j < 500 - 1; j++) {
			cout << "ba";
		}
		cout << endl;
	}
	return 0;
}
