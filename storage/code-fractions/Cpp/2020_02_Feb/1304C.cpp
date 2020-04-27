// Not submitted yet

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Customer {
public:
    int t;
    int low;
    int high;
    bool operator<(const Customer& RHS) const {
        return (this->t < RHS.t);
    }
};

int main() {
    int testcase;
    cin >> testcase;
    for (int tc = 0; tc < testcase; tc++) {
        int num_cus, init_t;
        cin >> num_cus >> init_t;

        // Containers for input
        vector<Customer> customers;
        customers.reserve(num_cus);
        int low_max = -1000000000;
        int high_min = 1000000000;
        // Getting input
        Customer cus;
        for (int i = 0; i < num_cus; i++) {
            cin >> cus.t >> cus.low >> cus.high;
            low_max = max(low_max, cus.low);
            high_min = min(high_min, cus.high);
            customers.push_back(cus);
        }


        stack<int> changes;
        bool possible = true;
        changes.push(0);
        //
        int temp_tracker = init_t;
        for (int i = 0; i < num_cus; i++) {
            if (temp_tracker > customers[i].high) {
                int amount_change = temp_tracker - customers[i].high;
                int change_time = customers[i].t - amount_change;
                if (change_time < changes.top()) {
                    possible = false;
                    break;
                }
                for (int j = i-1; j >= 0; j--) {
                    if (customers[j].t <= change_time) {
                        break;
                    }
                    if (temp_tracker - (customers[j].t - change_time) > customers[j].high || temp_tracker - (customers[j].t - change_time) < customers[j].low) {
                        possible = false;
                        break;
                    }
                }

                changes.push(change_time);
                temp_tracker = customers[i].high;

            }
            else if (temp_tracker < customers[i].low) {
                int amount_change = abs(temp_tracker - customers[i].low);
                int change_time = customers[i].t - amount_change;
                if (change_time < changes.top()) {
                    possible = false;
                    break;
                }
                for (int j = i-1; j >= 0; j--) {
                    if (customers[j].t <= change_time) {
                        break;
                    }
                    if (temp_tracker + (customers[j].t - change_time) > customers[j].high || temp_tracker + (customers[j].t - change_time) < customers[j].low) {
                        possible = false;
                        break;
                    }
                }

                changes.push(change_time);
                temp_tracker = customers[i].low;
            }
            if (!possible) {
                break;
            }
        }

        // print results
        if (possible) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
