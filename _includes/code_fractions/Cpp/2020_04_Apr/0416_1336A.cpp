/*
This code is an accepted solution to:
https://codeforces.com/contest/1336/problem/A
1336A, Linova and Kingdom
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void set_children_DFS(const int& current, vector<int>& depths, vector<int>& parents, vector<int>& num_children, const vector<vector<int>>& connected) {
    for (int i = 0; i < connected[current].size(); i++) {
        if (connected[current][i] == parents[current]) {
            continue;
        }
        int child = connected[current][i];
        parents[child] = current;
        depths[child] = depths[current]+1;
        set_children_DFS(child, depths, parents, num_children, connected);
        num_children[current] += num_children[child] + 1;
    }
}

long long get_happiness(const int& node, const vector<int>& depths, const vector<int>& parents, const vector<bool>& is_tourism) {
    if (is_tourism[node]) {
        return depths[node]+1;
    }
    else if (node == 0) {
        return 0;
    }
    else {
        return get_happiness(parents[node], depths, parents, is_tourism);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    // Containers
    vector<vector<int>> connected(n);
    vector<int> parents(n, -1);
    vector<int> depths(n);
    vector<int> num_children(n, 0);

    // Filling up containers from input
    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        connected[a-1].push_back(b-1);
        connected[b-1].push_back(a-1);
    }

    // Setting up data
    depths[0] = 0;
    set_children_DFS(0, depths, parents, num_children, connected);

    // Sorting for greedy
    vector<pair<int, int>> greedy_pair(n);
    for (int i = 0; i < n; i++) {
        greedy_pair[i].first = depths[i] - num_children[i];
        greedy_pair[i].second = i;
    }
    sort(greedy_pair.begin(), greedy_pair.end(), greater<pair<int, int>>());

    // Choose k nodes and set them non-tourism.
    vector<bool> is_tourism(n, true);
    for (int i = 0; i < k; i++) {
        is_tourism[greedy_pair[i].second] = false;
    }

    long long total_happiness = 0;
    for (int i = 0; i < n; i++) {
        if (!is_tourism[i] && (i == 0 || is_tourism[parents[i]])) {
            total_happiness += (num_children[i]+1) * get_happiness(i, depths, parents, is_tourism);
        }
    }

    cout << total_happiness << endl;

    return 0;
}
