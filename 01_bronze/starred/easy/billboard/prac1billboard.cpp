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

#define dbg(x) cerr << #x << " = " << (x) << '\n'


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

struct Board {
    pii ll, ur;  // lower-left and upper-right corners

    int area() const {
        return max(0, ur.f - ll.f) * max(0, ur.s - ll.s);
    }

    int overlap(const Board& other) const {
        int x_overlap = max(0, min(ur.f, other.ur.f) - max(ll.f, other.ll.f));
        int y_overlap = max(0, min(ur.s, other.ur.s) - max(ll.s, other.ll.s));
        return x_overlap * y_overlap;
    }
};

int main() {
    setIO("billboard"); // Change filename as needed
    Board a, b, truck;

    cin >> a.ll.f >> a.ll.s >> a.ur.f >> a.ur.s;
    cin >> b.ll.f >> b.ll.s >> b.ur.f >> b.ur.s;
    cin >> truck.ll.f >> truck.ll.s >> truck.ur.f >> truck.ur.s;

    int result = a.area() + b.area() - a.overlap(truck) - b.overlap(truck);
    cout << result << "\n";
    return 0;
}
