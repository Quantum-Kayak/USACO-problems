# USACO template🐮

``` cpp
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
template<typename T> void _print_sideways(const vector<T> &v) {
    cout << '[';
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        _print(v[i]);
    }
    cout << ']';
}

void _print(int x) { cout << x; }
void _print(long long x) { cout << x; }
void _print(unsigned x) { cout << x; }
void _print(unsigned long long x) { cout << x; }
void _print(double x) { cout << x; }
void _print(char x) { cout << '\'' << x << '\''; }
void _print(const string &x) { cout << '"' << x << '"'; }

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

#define dbg(...) cout << "[" << #__VA_ARGS__ << "] = ", __dbg(__VA_ARGS__)
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

/***** DSU (Disjoint Set Union) implementation *****/
vector<int> parent, size;

// Initialize single set void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

// Find representative with path compression
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

// Union by size
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

// DSU initialization for n elements
void init_dsu(int n) {
    parent.resize(n);
    size.assign(n, 1);
    for (int i = 0; i < n; ++i) parent[i] = i;
}

/***** Shortcuts *****/
#define pb push_back
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define sz(x) (int)(x).size()
#define each(a, x) for (auto& a : x)

int main() {
    setIO(); // Change filename as needed for file I/O

    return 0;
}
```
# 🐄 USACO Problems Repository

Welcome to my archive of solved USACO problems, organized for brutal clarity, long-term reference, and future self-roasting. Each problem includes:

- ✅ A `.cpp` file with the complete solution
- 🧠 A `README.md` (or `.XN.md`) with an explanation, strategy breakdown, and mental notes
- 🦥 Sometimes a `TLE.cpp` cause I was too slow
- ⌚ Some problems will have multiple solutions as part of mock contests, marked by `pracn`
- 🗂 Sorted by **division**, **difficulty**, and **problem metadata**

---

## 📁 Repository Structure

```text
USACO-problems/
├── bronze/
│   ├── starred/
│   │   ├── easy/
│   │   ├── normal/
│   │   ├── hard/
│   │   └── insane/
│   └── unstarred/
│       ├── easy/
│       ├── normal/
│       ├── hard/
│       └── insane/
├── silver/
│   └── starred/...
├── gold/
│   └── ...
└── plat/
    └── ...
```
## 🎯 Naming Convention

Each problem folder contains:

- `problemname.cpp` → The actual C++ solution  
- `problemname.md` → Writeup and explanation  
- `problemname.XN.md` → If the problem is cursed, deranged, or deserves its own therapy session  

**Examples:**
```text
bronze/starred/easy/blockgame/
├── blockgame.cpp
└── blockgame.md

silver/unstarred/hard/fencedin/
├── fencedin.cpp
└── fencedin.XN.md
```

# 🐄 Problem Name – USACO [Division] ([Month Year])

This directory contains a C++ solution to the **"[Problem Name]"** problem from the USACO [Division] division.

## 📜 Problem Summary
> Your own words summary of what’s going on, who’s angry (usually cows), and what you’re solving.

## 📥 Input Format
- Line-by-line breakdown
- Optional sample input

## 📤 Output Format
- What it prints
- Optional example output

## 💡 Strategy
- Key idea / pattern used
- Edge cases handled
- Algorithm + time complexity

## 🚀 How to Run
```sh
g++ -std=c++17 -o problem problem.cpp
./problem < input.txt > output.txt
```
## 🧠 **Time Complexity**  
Break it down cleanly:

- Reading/expanding segments: O(n + m)  
- Comparison loop: O(100)  
- Overall: O(n + m)
  
🔖 Tags  
division difficulty topics regret

```
division difficulty topics regret
```

---

## 🛠 Why This Exists

- To **practice USACO-style competitive programming**  
- To **build searchable knowledge** of problem-solving patterns  
- To **leave behind a map** for myself (and maybe others) on how I solved — or suffered through — each problem  

---

Happy coding. May your segments never overflow, and your trees remain acyclic.  
---
