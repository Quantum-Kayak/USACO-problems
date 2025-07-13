#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cmath>
#include <climits>
#include <iomanip>
#include <cassert>
#include <fstream>
#include <bitset>
#include <numeric>

using namespace std;

// Type aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vpi = vector<pii>;
using vpl = vector<pll>;

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;

// Constants
const ll INF = 1e18;
const int MX = 2e5 + 5;   // adjust per problem constraints

// Fast IO
void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// Debug (remove or disable before submitting)
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define dbg2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << '\n';

// Macros
#define pb push_back
#define all(x) x.begin(), x.end()
#define f first
#define s second

int N;

int dfs(int node, int current_number, vector<vector<int>>& graph, vector<int>& color) {
    if (node > N) {
        return current_number;
    }

    int min_result = INT_MAX;

    for (int c = 1; c <= 4; ++c) {
        bool valid = true;

        for (int neighbor : graph[node]) {
            if (color[neighbor] == c) {
                valid = false;
                break;
            }
        }

        if (valid) {
            color[node] = c;
            int result = dfs(node + 1, current_number * 10 + c, graph, color);
            min_result = min(min_result, result);
            color[node] = 0; 
        }
    }

    return min_result;
}


int main() {
    setIO("revegetate");  // Replace with actual filename
    int n, m, a, b;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    N = n;
    vi color(N + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        adj[b].pb(a);
        adj[a].pb(b);
    }
    int result = dfs(1, 0, adj, color);
    
    cout << result << '\n';

    return 0;
}
