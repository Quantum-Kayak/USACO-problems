#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

void setIO(const string &name) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<vector<int>> adj;
vector<int> breed;

bool bfs(int start, int target, int breedToFind) {
    vector<bool> visited(breed.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (breed[node] == breedToFind) return true;
        if (node == target) break;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

int main() {
    setIO("milkvisits");

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    breed.resize(n + 1);

    // Read in cow breeds
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        breed[i] = c - '0';
    }

    // Read in the tree
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Process queries
    for (int i = 0; i < m; i++) {
        int A, B, c;
        cin >> A >> B >> c;
        cout << (bfs(A, B, c) ? '1' : '0');
    }
    cout << endl;

    return 0;
}
