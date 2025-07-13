#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <deque>
#include <bitset>
#include <cmath>

using namespace std;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;

#define pb push_back
#define all(x) x.begin(), x.end()

struct Cow {
    int x, y, power;
};

bool canReach(const Cow& a, const Cow& b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy <= 1LL * a.power * a.power;
}

void bfs(int start, const vector<vi>& adj, vi& distance) {
    int n = adj.size();
    vb visited(n, false);
    queue<int> q;

    visited[start] = true;
    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    setIO("moocast"); 
    int n;
    cin >> n;
    
    vector<Cow> herd(n);
    for (int i = 0; i < n; i++) {
        cin >> herd[i].x >> herd[i].y >> herd[i].power;
    }

    vector<vi> adj(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && canReach(herd[i], herd[j])) {
                adj[i].pb(j);
            }
        }
    }

    int maxReach = 0;
    for (int i = 0; i < n; ++i) {
        vi distance(n, -1);
        bfs(i, adj, distance);
        int reachable = count_if(all(distance), [](int d) { return d != -1; });
        maxReach = max(maxReach, reachable);
    }

    cout << maxReach << '\n';
    return 0;
}

