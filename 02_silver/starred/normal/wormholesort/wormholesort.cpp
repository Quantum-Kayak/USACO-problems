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

struct DSU {
    vector<int> p, r;
    DSU(int n = 0) : p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) ++r[a];
        return true;
    }
};

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(),  "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct Edge { int a, b, w; };

int main() {
    setIO("wormsort"); 

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<int> p(N);
    for (int &x : p) { cin >> x; --x; }

    bool sorted = true;
    for (int i = 0; i < N; ++i) if (p[i] != i) { sorted = false; break; }
    if (sorted) { cout << -1 << '\n'; return 0; }

    vector<Edge> edges(M);
    int maxW = 0;
    for (auto &e : edges) {
        cin >> e.a >> e.b >> e.w;
        --e.a; --e.b;
        maxW = max(maxW, e.w);
    }

    sort(edges.begin(), edges.end(),
         [](const Edge& x, const Edge& y){ return x.w > y.w; });

    auto can = [&](int W) -> bool {
        DSU dsu(N);
        for (const auto &e : edges)
            if (e.w >= W) dsu.unite(e.a, e.b);
            else break; 
        for (int i = 0; i < N; ++i)
            if (dsu.find(i) != dsu.find(p[i]))
                return false;
        return true;
    };

    int lo = 1, hi = maxW, ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (can(mid)) { ans = mid; lo = mid + 1; }
        else          { hi = mid - 1; }
    }
    cout << ans << '\n';
    return 0;
}
