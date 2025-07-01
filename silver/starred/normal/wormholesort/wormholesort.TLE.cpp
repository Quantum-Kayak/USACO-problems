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

// Type Aliases
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
using vvi = vector<vi>;

// Constants
const ll INF = 1e9;
const int MX = 2e5 + 5;

// Fast IO for USACO
void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    cerr << "File input attempted.\n";
}

// Debugging Macros
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#define dbg2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << '\n'

// Debug for vectors
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (int i = 0; i < (int)v.size(); ++i)
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    return os << "]";
}

template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    for (auto it = s.begin(); it != s.end(); ++it)
        os << *it << (next(it) == s.end() ? "" : ", ");
    return os << "}";
}

// Binary Search Helpers
template <typename T>
int lb(const vector<T>& v, T val) {
    return lower_bound(v.begin(), v.end(), val) - v.begin();
}
template <typename T>
int ub(const vector<T>& v, T val) {
    return upper_bound(v.begin(), v.end(), val) - v.begin();
}

// Shortcuts
#define pb push_back
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define sz(x) (int)(x).size()
#define each(a, x) for (auto& a : x)

struct wormhole {
    int a, b, w;
};

void dfs(int node, vvi& adj, vb& visited, vi& component) {
    visited[node] = true;
    component.pb(node);
    each(neighbor, adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, component);
        }
    }
};

bool can(int w, const vector<wormhole>& h, const vi& cows, const vi& sorted, int n) {
    vvi adj(n); 
    
    for (auto hole : h) {
        if (hole.w >= w) {
            adj[hole.a - 1].pb(hole.b - 1);
            adj[hole.b - 1].pb(hole.a - 1);
        }
    }
    
    vb visited(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            
            dfs(i, adj, visited, component);
            
            vi ccow, tcow;
            vi currentCows, targetCows;
            
            for (int j : component) {
                currentCows.pb(cows[j]);
                targetCows.pb(sorted[j]);
            }
            
            sort(all(currentCows));
            sort(all(targetCows));
                
            if (currentCows != targetCows) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    setIO("wormsort"); // Change filename as needed
    int n, m;
    cin >> n >> m;
    vector<wormhole> h(m);
    vi sorted(n);
    vb visited(n);
    
    for (int i = 0; i < n; i++) {
        cin >> sorted[i];
    }
    
    vi cows = sorted;
    sort(all(sorted));
    
    for (int i = 0; i < m; i++) {
        cin >> h[i].a >> h[i].b >> h[i].w;
    }
    
    if (cows == sorted) {
        cout << -1 << '\n';
        return 0;
    }
    
    int lo = 1, hi = INF, ans = -1;
    
    while (lo <= hi) {
        int mid = (lo + (hi - lo))/2;
            
        if (can(mid, h, cows, sorted, n)) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    
    cout << ans;
    return 0;
}
