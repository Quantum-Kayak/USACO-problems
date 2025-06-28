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

int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<ll> h(N);
        for (ll &x : h) cin >> x;

        if (N == 1) { 
            cout << 0 << '\n';
            continue;
        }
        
        ll coef_prevprev = 0, const_prevprev = 0; 
        ll coef_prev     = 1, const_prev     = 0;

        ll evenConstSum = 0, oddConstSum = 0;
        ll minX0Needed  = 0;    
        bool bad = false;

        for (int i = 0; i < N - 1 && !bad; ++i) {
            ll coef_next  = coef_prevprev;
            ll const_next = h[i + 1] - h[i] + const_prevprev;

            if (coef_next == 0) {  
                if (const_next < 0) bad = true; 
                oddConstSum += const_next;
            } else {
                evenConstSum += const_next;
                minX0Needed = max(minX0Needed, -const_next);
            }

            coef_prevprev = coef_prev;
            const_prevprev = const_prev;
            coef_prev = coef_next;
            const_prev = const_next;
        }

        if (bad) {
            cout << -1 << '\n';
            continue;
        }

        ll lastCoef = coef_prev, lastConst = const_prev;
        ll x0 = -1;

        if (N & 1) {                         
            x0 = -lastConst;
            if (x0 < 0 || x0 > h[0]) {
                cout << -1 << '\n';
                continue;
            }
        } else {                                  
            if (lastConst != 0) {
                cout << -1 << '\n';
                continue;
            }
            if (minX0Needed > h[0]) {         
                cout << -1 << '\n';
                continue;
            }
            x0 = minX0Needed;                       
        }

        ll evenCnt = (N + 1) / 2;  
        ll totalOps = evenCnt * x0 + evenConstSum + oddConstSum;
        cout << 2 * totalOps << '\n';    
    }
    return 0;
}
