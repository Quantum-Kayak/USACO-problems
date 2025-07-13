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
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "[";
	for (int i = 0; i < (int)v.size(); i++)
		os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
	return os << "]";
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

int main() {
    setIO("hoofball");
    int n;
    cin >> n;
    vector<pii> x(n);
    vi adj(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i].f;
        x[i].s = i;
    }

    sort(all(x)); 

    for (int i = 0; i < n; i++) {
        int idx = x[i].s;
        if (i == 0) {
            adj[idx] = x[i + 1].s;
        } else if (i == n - 1) {
            adj[idx] = x[i - 1].s;
        } else {
            int left_dist = x[i].f - x[i - 1].f;
            int right_dist = x[i + 1].f - x[i].f;
            if (left_dist <= right_dist) {
                adj[idx] = x[i - 1].s;
            } else {
                adj[idx] = x[i + 1].s;
            }
        }
    }

    vi indegree(n);
    for (int i = 0; i < n; i++) {
        indegree[adj[i]]++;
    }

    vb visited(n, false);
    
    int balls = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0 && !visited[i]) {
            int cur = i;
            while (!visited[cur]) {
                visited[cur] = true;
                cur = adj[cur];
            }
            balls++;
        }
    }

    for (int i = 0; i < n; i++) {
        int j = adj[i];
        if (!visited[i] && adj[j] == i) {
            visited[i] = visited[j] = true;
            balls++;
        }
    }

    cout << balls;
    return 0;
}
