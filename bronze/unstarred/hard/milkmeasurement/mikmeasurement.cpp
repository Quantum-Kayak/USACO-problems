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
struct log_ {
    int day;
    string cow;
    int x;
};

int main() {
    setIO("measurement");
    int n, Mildred = 7, Bessie = 7, Elsie = 7, count = 0;
    cin >> n;
    vector<log_> book(n);
    vector<string> bbest(3);

    for (int i = 0; i < n; i++) {
        cin >> book[i].day >> book[i].cow >> book[i].x;
    }
    
    sort(all(book), [](const log_& a, const log_& b) {
        return a.day < b.day;
    });

    map<string, int> milk = {{"Mildred", 7}, {"Elsie", 7}, {"Bessie", 7}};
    vector<string> best = {"Bessie", "Elsie", "Mildred"};

    for (int i = 0; i < n; i++) {
        milk[book[i].cow] += book[i].x;

        int top = max({milk["Mildred"], milk["Elsie"], milk["Bessie"]});
        vector<string> bbest;

        for (auto& [name, value] : milk) {
            if (value == top) bbest.push_back(name);
        }

        sort(all(bbest)); sort(all(best));
        if (bbest != best) count++;
        best = bbest;
    }

    cout << count;
    return 0;
}
