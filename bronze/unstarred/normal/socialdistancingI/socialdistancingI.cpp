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

/*****  Constants  *****/
constexpr ll  INF64 = (ll)4e18;        // ~2^62
constexpr int INF32 = 1e9+7;
constexpr int MX    = 2e5 + 5;

/*****  Fast I/O Setup (contest + local)  *****/
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
            cerr << "⚠️  Failed to open " << name << ".in/out. Using stdio.\n";
        }
    }
#endif
}

/*****  Debugging Tools  *****/
#define LOCAL
#ifdef LOCAL
  #include <iostream>
  using namespace std;

  #define dbg(x) cerr << #x << " = " << (x) << '\n'
  #define dbg2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << '\n'
  #define dbg3(x, y, z) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << '\n'

  template<typename T, typename... Args>
  void debug_out(const T& first, const Args&... rest) {
      cerr << first;
      ((cerr << ", " << rest), ...);
      cerr << '\n';
  }

  #define dbgv(...) cerr << "[" << #__VA_ARGS__ << "] = ", debug_out(__VA_ARGS__)

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

  template <typename T>
  ostream& operator<<(ostream& os, const unordered_set<T>& s) {
      os << "{";
      for (auto it = s.begin(); it != s.end(); ++it)
          os << *it << (next(it) == s.end() ? "" : ", ");
      return os << "}";
  }

  template <typename K, typename V>
  ostream& operator<<(ostream& os, const map<K, V>& m) {
      os << "{";
      for (auto it = m.begin(); it != m.end(); ++it)
          os << it->first << ": " << it->second << (next(it) == m.end() ? "" : ", ");
      return os << "}";
  }

  template <typename K, typename V>
  ostream& operator<<(ostream& os, const unordered_map<K, V>& m) {
      os << "{";
      for (auto it = m.begin(); it != m.end(); ++it)
          os << it->first << ": " << it->second << (next(it) == m.end() ? "" : ", ");
      return os << "}";
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

int main() {
    setIO("socdist1");
    int N;
    string s;
    if (!(cin >> N >> s)) return 0;

    vector<int> pos;  
    for (int i = 0; i < N; ++i)
        if (s[i] == '1') pos.push_back(i);

    if (pos.empty()) {
        cout << N - 1 << '\n';
        return 0;
    }

    int origMin = INT_MAX;
    for (int i = 1; i < (int)pos.size(); ++i)
        origMin = min(origMin, pos[i] - pos[i - 1]);

    vector<int> best1; 
    vector<int> best2; 

    int L = pos.front();
    if (L > 0) {
        best1.push_back(L);
        if (L >= 2) best2.push_back(L / 2);
    }

    for (int i = 0; i + 1 < (int)pos.size(); ++i) {
        int gap = pos[i + 1] - pos[i] - 1;
        if (gap == 0) continue;
        best1.push_back((gap + 1) / 2);   
        if (gap >= 2) best2.push_back((gap + 1) / 3);
    }

    L = N - 1 - pos.back();
    if (L > 0) {
        best1.push_back(L);
        if (L >= 2) best2.push_back(L / 2);
    }

    int candDiff = 0;
    if (best1.size() >= 2) {
        nth_element(best1.begin(), best1.begin() + 1, best1.end(), greater<>());
        candDiff = min(best1[0], best1[1]);      // smaller of the two
    }

    int candSame = best2.empty() ? 0 : *max_element(best2.begin(), best2.end());

    int bestNew = max(candDiff, candSame);

    cout << min(origMin, bestNew) << '\n';
    return 0;
}
