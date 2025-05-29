#include <bits/stdc++.h>
using namespace std;

void setIO(const string &name) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

bool reach(int start, vector<vector<int>>& reversed_adj, int n) {
    vector<bool> visited(n + 1, false);
    dfs(start, reversed_adj, visited);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    setIO("factory");
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    vector<vector<int>> reversed_adj(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int neighbor : adj[i]) {
            reversed_adj[neighbor].push_back(i);
        }
    }

    int candidate = -1;
    for (int i = 1; i <= n; i++) {
        if (reach(i, reversed_adj, n)) {
            if (candidate == -1) {
                candidate = i;
            } else {
                candidate = -1;
                break;
            }
        }
    }

    cout << candidate << '\n';
    return 0;
}
