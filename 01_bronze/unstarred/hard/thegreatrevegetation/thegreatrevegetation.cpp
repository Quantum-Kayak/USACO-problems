#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

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
// Macros
#define pb push_back
#define all(x) x.begin(), x.end()
#define f first
#define s second

int main() {
    setIO("revegetate");  // Replace with actual filename
    int n, m, a, b;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    vi color(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        adj[b].pb(a);
        adj[a].pb(b);
    }
    for (int i = 1; i <= n; ++i) {
        set<int> used;
        for (int neighbor : adj[i]) {
            if (color[neighbor]) used.insert(color[neighbor]);
        }
        for (int g = 1; g <= 4; ++g) {
            if (!used.count(g)) {
                color[i] = g;
                break;
            }
        }
    }
    
    for (int i = 1; i <= n; ++i)
        cout << color[i];
    cout << '\n';
    return 0;
}
