
// =====================
// ===  Standard Headers  ===
// =====================
#include <iostream>     // cin, cout
#include <vector>       // vector
#include <algorithm>    // sort, max, min, lower_bound
#include <cmath>        // sqrt, abs, pow
#include <numeric>      // accumulate, iota, gcd
#include <queue>        // queue, priority_queue
#include <stack>        // stack
#include <map>          // map
#include <set>          // set
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <string>       // string, to_string, substr
#include <limits>       // numeric_limits
#include <cassert>      // assert (optional, for testing)
#include <fstream>
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
#define for_subsets(sub, mask) for (int sub = mask; sub; sub = (sub - 1) & mask)

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

void setIO(const std::string& filename = "") {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (!filename.empty()) {
        static std::ifstream fin(filename + ".in");
        static std::ofstream fout(filename + ".out");

        if (!fin.is_open()) {
            std::cerr << "Error: Could not open input file: " << filename << ".in\n";
            std::exit(EXIT_FAILURE);
        }
        if (!fout.is_open()) {
            std::cerr << "Error: Could not open output file: " << filename << ".out\n";
            std::exit(EXIT_FAILURE);
        }

        std::cin.rdbuf(fin.rdbuf());
        std::cout.rdbuf(fout.rdbuf());
    }
}
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

// ====================
// ===== Packages =====
//=====================

// =====================
// ===  Main Driver  ===
// =====================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    setIO(); // Change filename as needed for file I/O
    vi abc(7);
    int a, b, c;
    for (int i = 0; i < 7; i++) {
        cin >> abc[i];
    }

    sort(all(abc));

    a = abc[6] - abc[5];
    b = abc[6] - abc[4];
    c = abc[6] - a - b;
    cout << a  << " " << b << " " << c; 
    return 0;
}
