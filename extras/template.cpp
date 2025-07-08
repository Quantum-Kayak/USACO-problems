#define LOCAL

// =====================
// ===  Standard Headers  ===
// =====================
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
#include <ctime>        // if you're playing with time (why?)
#include <functional>   // function objects (functors, lambdas)
#include <list>         // doubly-linked list (you’ll never need this)
#include <array>        // fixed-size array with bounds checking
#include <fstream>      // file I/O (for testing maybe)
#include <iomanip>      // manipulators for I/O formatting
#include <sstream>      // string streams (for the deranged)
#include <numeric>      // accumulate, iota, etc.
#include <valarray>     // the redheaded stepchild of containers
#include <cctype>       // char functions like isdigit, isalpha, etc.
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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
// ===  Constants  ===
// =====================
constexpr ll  INF64 = (ll)4e18;        // Very large number for 64-bit integer
constexpr int INF32 = 1e9+7;           // Common large number for 32-bit
constexpr int MX    = 2e5 + 5;         // Useful upper bound for array sizes

// =====================
// ===  Fast I/O Setup  ===
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

ll powmod(ll a,ll e,ll mod){
    ll r=1;
    for(;e;e>>=1,a=a*a%mod) if(e&1) r=r*a%mod;
    return r;
}

// =====================
// ===  Custom Hashing  ===
// =====================
struct pair_hash {
    size_t operator()(pii p) const {
        return ((uint64_t)p.first << 32) ^ p.second;
    }
};

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

// =====================
// ===  Main Driver  ===
// =====================
int main() {
    setIO(); // Change filename as needed for file I/O

    return 0;
}
