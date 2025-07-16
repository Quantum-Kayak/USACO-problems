#define LOCAL

// =====================
// ===  Standard Headers  ===
// =====================
#include <chrono>       // for the hash
#include <iostream>     // standard I/O
#include <cstdio>       // C-style I/O
#include <cstdlib>      // standard library stuff
#include <cstring>      // C-style strings
#include <string>       // C++ strings
#include <cmath>        // math functions
#include <algorithm>    // sort, binary_search, etc.
#include <vector>       // dynamic arrays
#include <deque>        // double-ended queues
#include <queue>        // FIFO, priority queues
#include <stack>        // LIFO stack
#include <map>          // associative array (balanced BST)
#include <unordered_map>// hash table map
#include <set>          // balanced BST set
#include <unordered_set>// hash set
#include <bitset>       // fixed-size bit arrays
#include <utility>      // pairs
#include <tuple>        // tuples
#include <climits>      // INT_MAX, etc.
#include <limits>       // numeric_limits
#include <cassert>      // assert
#include <functional>   // function objects (functors, lambdas)
#include <array>        // fixed-size array with bounds checking
#include <fstream>      // file I/O (for testing maybe)
#include <iomanip>      // manipulators for I/O formatting
#include <numeric>      // accumulate, iota, etc.
#include <cctype>       // char functions like isdigit, isalpha, etc.
#include <cstdint>

using namespace std;

// =====================
// ===  Macro Shortcuts  ===
// =====================
#define pb push_back
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define sz(x) (int)(x).size()
#define each(a, x) for (auto& a : x)

// =====================
// ===  Type Aliases and Typedefs  ===
// =====================
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
using vc = vector<char>;
using vvc = vector<vector<char>>;

template<class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// =====================
// ===   Constants   ===
// =====================
constexpr ll  INF64 = (ll)4e18;        // Very large number for 64-bit integer
constexpr int INF32 = 1e9+7;           // Common large number for 32-bit
constexpr int MX    = 2e5 + 5;         // Useful upper bound for array sizes
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int BASE = 127;
const int MOD = MOD1;
// =====================
// === Fast I/O Setup ===
// =====================
ifstream fin;
ofstream fout;

#ifdef LOCAL
    #define USE_FILE_IO
#endif

void setIO(const string &name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef USE_FILE_IO
    if (!name.empty()) {
        fin.open(name + ".in");
        fout.open(name + ".out");

        if (fin) {
            cin.rdbuf(fin.rdbuf());  // Redirect cin to file
        } else {
            cout << "\u26A0\uFE0F  Could not open " << name << ".in\n";
        }

        if (fout) {
            cout.rdbuf(fout.rdbuf()); // Redirect cout to file
        } else {
            cout << "\u26A0\uFE0F  Could not open " << name << ".out\n";
        }
    } else {
        cout << "\u26A0\uFE0F  No filename provided. Using standard input/output.\n";
    }
#endif
}

// =====================
// ===   Fread I/O   ===
// =====================

char inbuf[1 << 20];
int inpos = 0, inlen = 0;

inline char next() {
    if (inpos == inlen) {
        inpos = 0;
        inlen = fread(inbuf, 1, sizeof(inbuf), stdin);
        if (inlen == 0) return EOF;
    }
    return inbuf[inpos++];
}

// === Input ===

// Integer
inline int r_int() {
    int x = 0, neg = 0;
    char c = next();
    while (c < '0' || c > '9') {
        if (c == '-') neg = 1;
        c = next();
    }
    while ('0' <= c && c <= '9') {
        x = x * 10 + (c - '0');
        c = next();
    }
    return neg ? -x : x;
}

// Long long
inline long long r_ll() {
    long long x = 0; int neg = 0;
    char c = next();
    while (c < '0' || c > '9') {
        if (c == '-') neg = 1;
        c = next();
    }
    while ('0' <= c && c <= '9') {
        x = x * 10 + (c - '0');
        c = next();
    }
    return neg ? -x : x;
}

// Char (skip whitespace)
inline char r_char() {
    char c = next();
    while (c == ' ' || c == '\n' || c == '\r') c = next();
    return c;
}

// Word (whitespace-delimited)
inline string r_string() {
    string s;
    char c = next();
    while (c == ' ' || c == '\n' || c == '\r') c = next();
    while (c != ' ' && c != '\n' && c != '\r' && c != EOF) {
        s += c;
        c = next();
    }
    return s;
}

// Full line (newline-delimited)
inline string r_line() {
    string s;
    char c = next();
    while (c == '\n' || c == '\r') c = next(); // skip leading newlines
    while (c != '\n' && c != '\r' && c != EOF) {
        s += c;
        c = next();
    }
    return s;
}

// === Buffered Output ===
char outbuf[1 << 20];
int outp = 0;

inline void w_char(char c) {
    outbuf[outp++] = c;
}

inline void w_string(const char* s) {
    while (*s) outbuf[outp++] = *s++;
}

inline void w_string(const string &s) {
    for (char c : s) outbuf[outp++] = c;
}

inline void w_int(int x) {
    if (x == 0) {
        outbuf[outp++] = '0';
        return;
    }
    if (x < 0) {
        outbuf[outp++] = '-';
        x = -x;
    }
    char tmp[12];
    int len = 0;
    while (x) {
        tmp[len++] = (x % 10) + '0';
        x /= 10;
    }
    while (len--) outbuf[outp++] = tmp[len];
}

inline void w_ll(long long x) {
    if (x == 0) {
        outbuf[outp++] = '0';
        return;
    }
    if (x < 0) {
        outbuf[outp++] = '-';
        x = -x;
    }
    char tmp[20];
    int len = 0;
    while (x) {
        tmp[len++] = (x % 10) + '0';
        x /= 10;
    }
    while (len--) outbuf[outp++] = tmp[len];
}

inline void flush() {
    fwrite(outbuf, 1, outp, stdout);
    outp = 0;
}

// =====================
// ===  Debug Utilities  ===
// =====================
#ifdef LOCAL
void _print(int x) { cout << x; }
void _print(long long x) { cout << x; }
void _print(unsigned x) { cout << x; }
void _print(unsigned long long x) { cout << x; }
void _print(double x) { cout << x; }
void _print(char x) { cout << '\'' << x << '\''; }
void _print(const string &x) { cout << '"' << x << '"'; }

template<typename T> void _print_sideways(const vector<T> &v) {
    cout << '[';
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        _print(v[i]);
    }
    cout << ']';
}

template<typename T>
void _print(const vector<T> &v) { _print_sideways(v); }

template<typename T>
void _print(const vector<vector<T>> &v) {
    for (const auto &row : v) {
        _print_sideways(row);
        cout << '\n';
    }
}

void _print(const vector<pair<int, int>> &v) {
    for (const auto &[a, b] : v) {
        cout << a << ", " << b << '\n';
    }
}

template<typename T>
void _print(const set<T> &s) {
    for (const auto &x : s) {
        _print(x);
        cout << '\n';
    }
}

template<typename K, typename V>
void _print(const map<K, V> &m) {
    for (const auto &[key, val] : m) {
        _print(key);
        cout << " -> ";
        _print(val);
        cout << '\n';
    }
}

template<typename T>
void __dbg(const T &x) { _print(x); cout << '\n'; }

template<typename T, typename... Ts>
void __dbg(const T &first, const Ts&... rest) {
    _print(first); cout << " | ";
    __dbg(rest...);
}

#define dbg(...) cout << "[" << #__VA_ARGS__ << "] =\n", __dbg(__VA_ARGS__)
#else
#define dbg(...)
#endif

// =====================
// ===  Helper Functions  ===
// =====================
template<class T> inline bool chmin(T& a,const T& b){ return b<a ? a=b,1:0; }
template<class T> inline bool chmax(T& a,const T& b){ return b>a ? a=b,1:0; }
template<class T> int lb(const vector<T>& v,const T& x){ return lower_bound(v.begin(),v.end(),x)-v.begin(); }
template<class T> int ub(const vector<T>& v,const T& x){ return upper_bound(v.begin(),v.end(),x)-v.begin(); }
template<class T> T ceil_div(T a,T b){ return (a+b-1)/b; }
template<class T> T floor_div(T a, T b) { return a / b - ((a ^ b) < 0 && a % b); }

// string stuff
vector<string> chunk(const string& s, int k) {
    vector<string> chunks;
    for (int i = 0; i < (int)s.size(); i += k) {
        chunks.push_back(s.substr(i, min(k, (int)s.size() - i)));
    }
    return chunks;
}

bool is_rep(const string& s, int k) {
    if (s.size() % k != 0) return false;
    string base = s.substr(0, k);
    for (int i = k; i < (int)s.size(); i += k) {
        if (s.substr(i, k) != base)
            return false;
    }
    return true;
}

vector<string> all_subs(const string& s) {
    vector<string> res;
    int n = s.size();
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            res.push_back(s.substr(i, j - i + 1));
    return res;
}

ll powmod(ll a,ll e,ll mod){
    ll r=1;
    for(;e;e>>=1,a=a*a%mod) if(e&1) r=r*a%mod;
    return r;
}

vi prefix_function(const string& s) {
    int n = sz(s);
    vi pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

ll modinv(ll a, ll m = MOD) {
    return powmod(a, m - 2, m);  // Assumes m is prime
}

// =====================
// ===  Disjoint Set Union (DSU)  ===
// =====================
struct DSU {
    vi parent, rank, size;
    int components;

    DSU(int n) { init(n); }

    void init(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        size.assign(n, 1);
        iota(all(parent), 0);
        components = n;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;

        if (rank[rx] < rank[ry]) swap(rx, ry);
        parent[ry] = rx;
        size[rx] += size[ry];
        if (rank[rx] == rank[ry]) rank[rx]++;
        components--;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }
    int get_size(int x) { return size[find(x)]; }
    int count() const { return components; }
    bool is_leader(int x) const { return parent[x] == x; }

    vi leaders() const {
        vi res;
        for (int i = 0; i < sz(parent); ++i)
            if (is_leader(i)) res.pb(i);
        return res;
    }

    vvi groups() {
        unordered_map<int, vi> g;
        for (int i = 0; i < sz(parent); ++i)
            g[find(i)].pb(i);
        vvi res;
        for (auto &[_, v] : g)
            res.pb(move(v));
        return res;
    }
};

double average(const vector<int>& nums) {
    if (nums.empty()) return 0.0;
    long long sum = 0;
    for (int x : nums) sum += x;
    return static_cast<double>(sum) / nums.size();
}

// =====================
// === Binary Search Utilities ===
// =====================

// Finds the smallest x in [lo, hi] such that check(x) == true
// Returns hi + 1 if no such x exists (i.e., all check(x) are false)
template<typename Func>
int binary_search_first_true(int lo, int hi, Func check) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return check(lo) ? lo : hi + 1;
};

// Finds the largest x in [lo, hi] such that check(x) == true
// Returns lo - 1 if no such x exists (i.e., all check(x) are false)
template<typename Func>
int binary_search_last_true(int lo, int hi, Func check) {
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2; // upper mid to prevent infinite loop
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return check(lo) ? lo : lo - 1;
};

// Example use-case for placeholder check
// Modify this based on the problem you are solving
bool check(int x) {
    // For example:
    // return (x * x >= target);  // Binary search square root
    // return (can_complete_in_time(x));  // Greedy scheduling
    return true; // default stub — always true (useless but compiles)
};

// =====================
// === Graph Search  ===
// =====================

int n, m;
vector<vector<pair<int, int>>> adj_weighted;
vector<vector<int>> adj_unweighted;

void build_graph(bool weighted) {
    n = r_int();
    m = r_int();
    if (weighted)
        adj_weighted.assign(n, {});
    else
        adj_unweighted.assign(n, {});

    for (int i = 0; i < m; ++i) {
        int u = r_int(), v = r_int();

        if (weighted) {
            int w = r_int();
            adj_weighted[u].push_back({v, w});
            adj_weighted[v].push_back({u, w}); // if undirected
        } else {
            adj_unweighted[u].push_back(v);
            adj_unweighted[v].push_back(u); // if undirected
        }
    }
}

//Unweighted Graph Search
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj_unweighted[u]) {
        if (!visited[v]) dfs(v);
    }
}

vector<int> dist;

void bfs(int start) {
    queue<int> q;
    dist.assign(n, -1);
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj_unweighted[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

//Weighted Graph Search
void dijkstra(int src) {
    dist.assign(n, INF32);
    dist[src] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto &[v, w] : adj_weighted[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

// =====================
// ===  0/1 Knapsack DP ===
// =====================

// 2D Version — reconstructable
int knapsack_2D(int n, int W, const vi &wt, const vi &val, vi &items_taken) {
    vvi dp(n + 1, vi(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            dp[i][w] = dp[i - 1][w];
            if (wt[i - 1] <= w)
                chmax(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
        }
    }

    // Optional: Reconstruct taken items
    items_taken.clear();
    int w = W;
    for (int i = n; i >= 1; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            items_taken.pb(i - 1);  // item index
            w -= wt[i - 1];
        }
    }
    reverse(all(items_taken));
    return dp[n][W];
}

// 1D Version — fast & memory-efficient
int knapsack_1D(int n, int W, const vi &wt, const vi &val) {
    vi dp(W + 1, 0);
    for (int i = 0; i < n; ++i)
        for (int w = W; w >= wt[i]; --w)
            chmax(dp[w], val[i] + dp[w - wt[i]]);
    return dp[W];
}

// Unbounded Version
int unbounded(int x, vi coins) {
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; ++i)
        for (int c : coins)
            if (i - c >= 0)
                dp[i] = (dp[i] + dp[i - c]) % MOD;
    return dp[x];
}

int two_sets(int n) {
    int S = n*(n+1)/2;
    if (S % 2) return 0;
    int target = S / 2;

    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = target; j >= i; --j)
            dp[j] = (dp[j] + dp[j - i]) % MOD;

    return dp[target] * modinv(2) % MOD;
}

// =====================
// ===  Custom Hashes  ===
// =====================

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    template<typename T1, typename T2>
    size_t operator()(pair<T1, T2> const& p) const {
        uint64_t h1 = operator()(static_cast<uint64_t>(p.first));
        uint64_t h2 = operator()(static_cast<uint64_t>(p.second));
        return h1 ^ (h2 << 1);
    }
};

struct RollingHash {
    vector<ll> h, p;

    RollingHash(const string& s) {
        int n = s.size();
        h.assign(n + 1, 0);
        p.assign(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            h[i + 1] = (h[i] * BASE + s[i] - 'a' + 1) % MOD;
            p[i + 1] = (p[i] * BASE) % MOD;
        }
    }

    ll get(int l, int r) { // 0-based, [l..r]
        return (h[r + 1] - h[l] * p[r - l + 1] % MOD + MOD) % MOD;
    }
};

struct DoubleHash {
    vector<int> h1, h2, p1, p2;

    DoubleHash(const string& s) {
        int n = s.size();
        h1.assign(n + 1, 0); h2.assign(n + 1, 0);
        p1.assign(n + 1, 1); p2.assign(n + 1, 1);

        for (int i = 0; i < n; ++i) {
            h1[i + 1] = (1LL * h1[i] * BASE + s[i]) % MOD1;
            h2[i + 1] = (1LL * h2[i] * BASE + s[i]) % MOD2;
            p1[i + 1] = (1LL * p1[i] * BASE) % MOD1;
            p2[i + 1] = (1LL * p2[i] * BASE) % MOD2;
        }
    }

    pair<int, int> get(int l, int r) {
        int x1 = (1LL * h1[r + 1] - 1LL * h1[l] * p1[r - l + 1] % MOD1 + MOD1) % MOD1;
        int x2 = (1LL * h2[r + 1] - 1LL * h2[l] * p2[r - l + 1] % MOD2 + MOD2) % MOD2;
        return {x1, x2};
    }
};

struct pair_hash {
    size_t operator()(pii p) const {
        return ((uint64_t)p.first << 32) ^ p.second;
    }
};

// =====================
// ===  Prefix Sums  ===
// =====================

// 1D sums
vi build_prefix(const vi& a) {
    int n = sz(a);
    vi prefix(n + 1, 0);
    for (int i = 0; i < n; ++i)
        prefix[i + 1] = prefix[i] + a[i];
    return prefix;
}

int range_sum(const vi& prefix, int l, int r) {
    // returns sum of a[l..r], inclusive
    return prefix[r + 1] - prefix[l];
}

// 2D sums
vvi build_prefix_2D(const vvi& grid) {
    int n = sz(grid), m = sz(grid[0]);
    vvi ps(n + 1, vi(m + 1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ps[i][j] = grid[i - 1][j - 1]
                     + ps[i - 1][j]
                     + ps[i][j - 1]
                     - ps[i - 1][j - 1];

    return ps;
}

int range_sum_2D(const vvi& ps, int x1, int y1, int x2, int y2) {
    // inclusive rectangle from (x1,y1) to (x2,y2)
    x1++, y1++, x2++, y2++;
    return ps[x2][y2]
         - ps[x1 - 1][y2]
         - ps[x2][y1 - 1]
         + ps[x1 - 1][y1 - 1];
}


// =====================
// ===  Main Driver  ===
// =====================

void solve() {
    // your logic goes here
}

int main() {
    setIO(); // Change filename as needed for file I/O
    flush();
    return 0;
}
