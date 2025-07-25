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
const ll INF = 1e18;
const int MX = 2e5 + 5;

// Fast IO for USACO
void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
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

struct cow {
    int start;
    int end;
    int buckets;
};

int main() {
    setIO("blist"); // Change filename as needed
    int n;
    cin >> n;
    vector<cow> cows(n);
    
    for (int i = 0; i < n; i++) {
        cin >> cows[i].start >> cows[i].end >> cows[i].buckets;
    }
    
    sort(all(cows), [](const cow& a, const cow& b) {
        return a.start < b.start;
    });
    
    int time_[1001] = {};
    for (auto& c : cows)
        for (int t = c.start; t <= c.end; t++)
            time_[t] += c.buckets;
    
    cout << *max_element(time_, time_ + 1001);
    return 0;
}
