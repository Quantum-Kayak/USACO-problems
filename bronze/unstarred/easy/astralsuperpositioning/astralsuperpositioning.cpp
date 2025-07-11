#define LOCAL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

// Min-priority queue alias using greater comparator
template<class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

/*****  Aliases & typedefs  *****/
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

/*****  Constants  *****/
constexpr ll  INF64 = (ll)4e18;        // Very large number for 64-bit integer
constexpr int INF32 = 1e9+7;          // Common large number for 32-bit
constexpr int MX    = 2e5 + 5;        // Useful upper bound for array sizes

/***** Fast IO with fallback *****/
ifstream fin;
ofstream fout;

#ifdef LOCAL
    #define USE_FILE_IO
#endif

// Fast I/O setup with optional file redirection
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

/*****  Debugging Tools  *****/
#ifdef LOCAL
// Debug print functions for various types
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

/*****  Helpers  *****/
template<class T> inline bool chmin(T& a,const T& b){ return b<a ? a=b,1:0; }
template<class T> inline bool chmax(T& a,const T& b){ return b>a ? a=b,1:0; }
template<class T> int lb(const vector<T>& v,const T& x){ return lower_bound(v.begin(),v.end(),x)-v.begin(); }
template<class T> int ub(const vector<T>& v,const T& x){ return upper_bound(v.begin(),v.end(),x)-v.begin(); }
template<class T> T ceil_div(T a,T b){ return (a+b-1)/b; }
// Fast modular exponentiation
ll powmod(ll a,ll e,ll mod){ ll r=1; for(;e;e>>=1,a=a*a%mod) if(e&1) r=r*a%mod; return r; }

/*****  pair hash for unordered_map / gp_hash_table  *****/
struct pair_hash{ size_t operator()(pii p) const { return ((uint64_t)p.first<<32)^p.second; } };

/***** Shortcuts *****/
#define pb push_back
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define sz(x) (int)(x).size()
#define each(a, x) for (auto& a : x)

/***** DSU (Disjoint Set Union) implementation *****/
struct DSU {
    vi parent, rank, size;
    int components;

    DSU(int n) {
        init(n);
    }

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

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int get_size(int x) {
        return size[find(x)];
    }

    int count() const {
        return components;
    }

    bool is_leader(int x) const {
        return parent[x] == x;
    }

    // Optional: get all component leaders
    vi leaders() const {
        vi res;
        for (int i = 0; i < sz(parent); ++i)
            if (is_leader(i)) res.pb(i);
        return res;
    }

    // Optional: get all elements by component
    // Only use this in small-medium n situations
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

const long long INF = (1LL << 60);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, A, B;
        cin >> N >> A >> B;

        vector<string> g(N);
        for (auto &row : g) cin >> row;
        
        if (A == 0 && B == 0) {
            long long ans = 0;
            for (int r = 0; r < N; ++r)
                for (int c = 0; c < N; ++c)
                    if (g[r][c] == 'G' || g[r][c] == 'B') ++ans;
            cout << ans << '\n';
            continue;
        }
        auto in = [&](int r, int c) { return 0 <= r && r < N && 0 <= c && c < N; };

        const int dr = B, dc = A;
        long long total = 0;
        bool impossible = false;

        vector<long long> dp_prev(3), dp_next(3);

        for (int r0 = 0; r0 < N && !impossible; ++r0)
            for (int c0 = 0; c0 < N && !impossible; ++c0) {
                if (in(r0 - dr, c0 - dc)) continue;
                            */
                dp_prev.assign(3, INF);
                dp_prev[0] = 0;

                for (int r = r0, c = c0; in(r, c); r += dr, c += dc) {
                    dp_next.assign(3, INF);

                    for (int prev = 0; prev < 3; ++prev) if (dp_prev[prev] < INF) {
                        int y = (prev == 2);
                        for (int nxt = 0; nxt < 3; ++nxt) {
                            int x = (nxt != 0);
                            bool ok = false;

                            switch (g[r][c]) {
                                case 'W': ok = (y == 0 && x == 0); break;
                                case 'B': ok = (y == 1 && x == 1); break;
                                case 'G': ok = (y + x == 1);       break;
                            }
                            if (!ok) continue;

                            long long cand = dp_prev[prev] + x;   
                            dp_next[nxt] = min(dp_next[nxt], cand);
                        }
                    }
                    if (dp_next[0] == INF && dp_next[1] == INF && dp_next[2] == INF) {
                        impossible = true; break;     
                    }
                    dp_prev.swap(dp_next);
                }

                total += *min_element(dp_prev.begin(), dp_prev.end());
            }

        cout << (impossible ? -1 : total) << '\n';
    }
    return 0;
}
