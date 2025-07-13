#include <bits/stdc++.h>
using namespace std;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;

int main() {
    setIO("fenceplan");
    int N, M;
    cin >> N >> M;

    vector<pii> coord(N);
    for (int i = 0; i < N; i++) {
        cin >> coord[i].first >> coord[i].second;
    }

    vector<vi> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;  // adjust to 0-based
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vb visited(N, false);
    int minPerimeter = INT_MAX;

    for (int cow = 0; cow < N; cow++) {
        if (!visited[cow]) {
            int minX = coord[cow].first;
            int maxX = coord[cow].first;
            int minY = coord[cow].second;
            int maxY = coord[cow].second;

            queue<int> q;
            q.push(cow);
            visited[cow] = true;

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                minX = min(minX, coord[cur].first);
                maxX = max(maxX, coord[cur].first);
                minY = min(minY, coord[cur].second);
                maxY = max(maxY, coord[cur].second);

                for (int neighbor : adj[cur]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            int perimeter = 2 * ( (maxX - minX) + (maxY - minY) );
            minPerimeter = min(minPerimeter, perimeter);
        }
    }

    cout << minPerimeter << endl;
    return 0;
}
