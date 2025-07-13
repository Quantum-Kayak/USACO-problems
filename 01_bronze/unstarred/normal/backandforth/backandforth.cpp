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

set<int> results;

void dfs(int day, vector<int>& A, vector<int>& B, int milkA, int milkB) {
	if (day == 4) {
		results.insert(milkA);
		return;
	}

	bool isATurn = (day % 2 == 0);
	auto& from = isATurn ? A : B;
	auto& to   = isATurn ? B : A;
	auto& milk_from = isATurn ? milkA : milkB;
	auto& milk_to   = isATurn ? milkB : milkA;

	for (int i = 0; i < from.size(); i++) {
		int size = from[i];

		vector<int> A_next = A, B_next = B;
		int milkA_next = milkA, milkB_next = milkB;

		if (isATurn) {
			milkA_next -= size;
			milkB_next += size;
			B_next.push_back(size);
			A_next.erase(A_next.begin() + i);
		} else {
			milkB_next -= size;
			milkA_next += size;
			A_next.push_back(size);
			B_next.erase(B_next.begin() + i);
		}

		dfs(day + 1, A_next, B_next, milkA_next, milkB_next);
	}
}

int main() {
	setIO("backforth");
	vi A(10), B(10);
	for (int i = 0; i < 10; i++) cin >> A[i];
	for (int i = 0; i < 10; i++) cin >> B[i];

	dfs(0, A, B, 1000, 1000);
	cout << results.size() << "\n";
}
