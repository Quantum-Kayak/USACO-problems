#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<bool> visited;
int count = 0;
vector<vector<pair<int, int>>> adj;
int threshold;

void setIO(const string &name) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void dfs(int v) {
    visited[v] = true;
    for (const auto& neighbor : adj[v]) {
        int next = neighbor.first;
        int weight = neighbor.second;
        if (!visited[next] && weight >= threshold) {
            count++;
            dfs(next);
        }
    }
}

int main() {
    setIO("mootube");
    int N, Q;
    cin >> N >> Q;

    adj.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        adj[p].push_back({q, r});
        adj[q].push_back({p, r});
    }

    for (int i = 0; i < Q; i++) {
        int k, v;
        cin >> k >> v;
        threshold = k;    
        visited.assign(N + 1, false);
        count = 0;
        dfs(v);
        cout << count << '\n';
    }

    return 0;
}
