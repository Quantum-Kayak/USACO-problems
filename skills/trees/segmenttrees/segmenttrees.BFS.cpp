#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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

void BFS(int start, int target) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << "visiting node " << current << endl;
        
        if (current == target) {
            cout << "found it at " << target << endl;
            return;
        }
        
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                cout << "queueing " << neighbor << endl;
            }
        }
    }
}

int main() {
    setIO("tree");
    
    int n, x, y;
    cin >> n >> x >> y;
    
    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout << "starting BFS from node " << x << " to find " << y << endl;
    BFS(x, y);

    return 0;
}
