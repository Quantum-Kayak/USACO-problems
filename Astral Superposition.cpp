#define LOCAL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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
constexpr ll  INF64 = (ll)4e18;        // ~2^62
constexpr int INF32 = 1e9+7;
constexpr int MX    = 2e5 + 5;

/***** Fast IO with fallback *****/
ifstream fin;
ofstream fout;

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    if (!name.empty()) {
        fin.open(name + ".in");
        fout.open(name + ".out");
        if (fin && fout) {
            #define cin fin
            #define cout fout
        } else {
            cerr << "⚠️  Failed to open files. Using standard input/output.\n";
        }
    } else {
        cerr << "Using standard input/output.\n";
    }
#endif
}

/*****  Debugging Tools  *****/
#ifdef LOCAL

#define dbg(x) cerr << #x << " = "; debug_out(x); cerr << '\n'
#define dbg2(x, y) cerr << #x << " = "; debug_out(x); cerr << ", " << #y << " = "; debug_out(y); cerr << '\n'
#define dbg3(x, y, z) cerr << #x << " = "; debug_out(x); cerr << ", " << #y << " = "; debug_out(y); cerr << ", " << #z << " = "; debug_out(z); cerr << '\n'
#define dbgv(...) cerr << "[" << #__VA_ARGS__ << "] = ", debug_out(__VA_ARGS__), cerr << '\n';

// Special case: vector<char> to avoid overload ambiguity
void debug_out(const vector<char>& v) {
    cerr << "{";
    for (int i = 0; i < (int)v.size(); ++i) {
        if (i) cerr << ", ";
        cerr << v[i];
    }
    cerr << "}";
}

/*****  Type Printers  *****/
template<typename T>
void debug_out(const T& val);

/*****  Primitive + String Types  *****/
template<typename T>
typename enable_if<!is_class<T>::value || is_same<T, string>::value || is_same<T, char>::value || is_same<T, bool>::value, void>::type
debug_out(const T& val) {
    cerr << val;
}

/*****  Pair Type  *****/
template<typename A, typename B>
void debug_out(const pair<A, B>& p) {
    cerr << "(";
    debug_out(p.first);
    cerr << ", ";
    debug_out(p.second);
    cerr << ")";
}

/*****  Tuple Type  *****/
template<size_t I = 0, typename... Tp>
typename enable_if<I == sizeof...(Tp), void>::type
print_tuple(const tuple<Tp...>&) {}

template<size_t I = 0, typename... Tp>
typename enable_if<I < sizeof...(Tp), void>::type
print_tuple(const tuple<Tp...>& t) {
    if (I > 0) cerr << ", ";
    debug_out(get<I>(t));
    print_tuple<I + 1, Tp...>(t);
}

template<typename... Args>
void debug_out(const tuple<Args...>& t) {
    cerr << "(";
    print_tuple(t);
    cerr << ")";
}

/*****  Optional Type  *****/
template<typename T>
void debug_out(const optional<T>& o) {
    if (o) {
        cerr << "opt(";
        debug_out(*o);
        cerr << ")";
    } else {
        cerr << "nullopt";
    }
}

/*****  Variant Type  *****/
template<typename... Types>
void debug_out(const variant<Types...>& v) {
    visit([](const auto& val) { debug_out(val); }, v);
}

/*****  Generic Container Printer (vector, set, map, etc.)  *****/
template<typename T>
auto debug_out(const T& container) -> decltype(container.begin(), container.end(), void()) {
    cerr << "{";
    bool first = true;
    for (const auto& val : container) {
        if (!first) cerr << ", ";
        debug_out(val);
        first = false;
    }
    cerr << "}";
}

/*****  Variadic Printer  *****/
template<typename T, typename... Args>
void debug_out(const T& first, const Args&... rest) {
    debug_out(first);
    ((cerr << ", ", debug_out(rest)), ...);
}

/*****  Matrix Printer  *****/
template<typename T>
void debug_out(const vector<vector<T>>& mat) {
    cerr << "[\n";
    for (const auto& row : mat) {
        cerr << "  ";
        debug_out(row);
        cerr << '\n';
    }
    cerr << "]";
}

#else
#define dbg(x)
#define dbg2(x, y)
#define dbg3(x, y, z)
#define dbgv(...)
#endif

/*****  Helpers  *****/
template<class T> inline bool chmin(T& a,const T& b){ return b<a ? a=b,1:0; }
template<class T> inline bool chmax(T& a,const T& b){ return b>a ? a=b,1:0; }
template<class T> int lb(const vector<T>& v,const T& x){ return lower_bound(v.begin(),v.end(),x)-v.begin(); }
template<class T> int ub(const vector<T>& v,const T& x){ return upper_bound(v.begin(),v.end(),x)-v.begin(); }
template<class T> T ceil_div(T a,T b){ return (a+b-1)/b; }
ll powmod(ll a,ll e,ll mod){ ll r=1; for(;e;e>>=1,a=a*a%mod) if(e&1) r=r*a%mod; return r; }

/*****  pair hash for unordered_map / gp_hash_table  *****/
struct pair_hash{ size_t operator()(pii p) const { return ((uint64_t)p.first<<32)^p.second; } };

/***** Shortcuts ******/
#define pb push_back
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define sz(x) (int)(x).size()
#define each(a, x) for (auto& a : x)

char rec(char color) {
    return (color == 'W' || color == 'G') ? '.' : '*';
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, b, c;
        cin >> n >> b >> c;
    
        vvc pic(n, vc(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> pic[i][j];
    
        vvc ans(n, vc(n, '.'));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans[i][j] = rec(pic[i][j]);
    
        dbg(ans);
    }
    return 0;
}
