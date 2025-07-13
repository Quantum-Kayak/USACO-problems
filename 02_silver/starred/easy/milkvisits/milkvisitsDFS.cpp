#include <iostream>
#include <fstream>
#include <vector>
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
bool foundBreed;

void dfs(int node, int target, int breedToFind, vector<bool>& visited) {
    if (breed[node] == breedToFind) foundBreed = true;
    if (node == target) return;

    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, target, breedToFind, visited);
        }
    }
}

int main() {
    setIO("milkvisits");

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    breed.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        breed[i] = c - '0';
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < m; i++) {
        int A, B, c;
        cin >> A >> B >> c;

        foundBreed = false;
        vector<bool> visited(n + 1, false);
        dfs(A, B, c, visited);

        cout << (foundBreed ? '1' : '0');
    }
    cout << endl;

    return 0;
}
