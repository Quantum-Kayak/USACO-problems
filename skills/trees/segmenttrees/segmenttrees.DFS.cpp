#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void setIO(const string &name) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
void DFS(int node, int target) {
    visited[node] = true;
    if (node == target) {
        cout << "found it at " << target << endl;
        return;
    }
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            cout << "going to " << neighbor << endl;
            DFS(neighbor, target);
            
        }
    }
};
int main() {
    setIO("tree"); 
    
    int n, x, y;
    cin >> n >> x >> y;
    
    adj.resize(n+1);
    visited.resize(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "visiting node " << x << endl;
    DFS(x, y);
    return 0;
}
