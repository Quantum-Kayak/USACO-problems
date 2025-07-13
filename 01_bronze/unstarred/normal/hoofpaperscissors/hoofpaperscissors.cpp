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

bool wins(int a, int b) {
    return (a == 1 && b == 3) || (a == 2 && b == 1) || (a == 3 && b == 2);
};

int countWins(int a, int b, const vector<pii>& rounds) {
    int winCount = 0;
    vector<int> mapping = {1, 2, 3};
    do {
        int cnt = 0;
        for (auto [x, y] : rounds) {
            int myGesture = mapping[x - 1];
            int oppGesture = mapping[y - 1];
            cnt += wins(myGesture, oppGesture);
        }
        winCount = max(winCount, cnt);
    } while (next_permutation(mapping.begin(), mapping.end()));
    return winCount;
}

int main() {
    setIO("hps");
    int n;
    cin >> n;
    vector<pii> g;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g.pb({a, b});
    }
    
    int ans = 0;
    for (int a = 1; a <= 3; a++) {
        for (int b = 1; b <= 3; b++) {
            ans = max(ans, countWins(a, b, g));
        }
    }
    cout << ans;
    return 0;
}
