#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> bfs(vector<int>& a, int A) {
    int n = a.size();
    set<vector<int>> visited;
    queue<pair<vector<int>, vector<pair<int,int>>>> q;

    q.push({vector<int>(n, 0), {}}); // start with empty vessels

    while (!q.empty()) {
        auto [state, operations] = q.front();
        q.pop();

        if (find(state.begin(), state.end(), A) != state.end()) {
            int index = distance(state.begin(), find(state.begin(), state.end(), A));
            operations.push_back({0, index+1});
            return operations;
        }

        for (int i = 0; i <; i++) {
            if (state[i] < a[i]) {
                vector<int> new_state = state;
                for (int j = 0; j <; j++) {
                    if (j != i) {
                        new_state[j] = min(a[j], new_state[j]+new_state[i]);
                    }
                }
                new_state[i] = 0;
                if (visited.find(new_state) == visited.end()) {
                    vector<pair<int,int>> new_operations = operations;
                    new_operations.push_back({i+1, 0});
                    q.push({new_state, new_operations                    visited.insert(new_state);
 }
            }
            if (state[i] > 0) {
                vector<int> new_state = state;
                new_state[i] = 0;
                if (visited.find(new_state) == visited.end()) {
                    vector<pair<int,int>> new_operations = operations;
                    new_operations.push_back({i+1, 0});
                    q.push({new_state, new_operations});
                    visited.insert(new_state);
                }
            }
            if (state[i] < a[i]) {
                vector<int> new_state = state;
                new_state[i] = a[i];
               visited.find(new_state) == visited.end()) {
                    vector<pair<int,int>> new_operations = operations;
                    new_operations.push_back({i+1, 0});
                    for (int j = 0; j < n; j++) {
                        if (j != i) {
                            new_operations.push_back({i+1, j+1});
                        }
                    }
                    q.push({new_state, new_operations});
                    visited.insert(new_state);
                }
            }
        }
    }

    return {}; // no solution found
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.in", "r", stdin);
//  freopen("out.out", "w", stdout);
#endif
    int n A;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> A;

    vector<pair<int,int>> operations = bfs(a, A);

    if (operations.empty()) {
        cout << 1 << "\n";
    } else {
        cout << operations.size() << "\n";
        for (auto [i, j] : operations) {
            cout << i << " << <<n";
        }
    }

    return 0;
}
