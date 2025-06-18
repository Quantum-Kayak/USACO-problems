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

// Type aliases
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

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;

// Constants
const ll INF = 1e18;
const int MX = 2e5 + 5;   // adjust per problem constraints

// Fast IO
void setIO(const string& name = "") {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

// Debug (remove or disable before submitting)
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define dbg2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << '\n';

// Macros
#define pb push_back
#define all(x) x.begin(), x.end()
#define f first
#define s second

ll e_round(ll i) {
	ll b_pow = 1;
	ll b = 0;
	while (b_pow <= i) {
		b_pow *= 10;
		b++;
	}
	ll y = i;
	for (ll p = 1; p <= b; p++) {
		ll z_pow = 1;
		for (ll j = 0; j < p - 1; j++) z_pow *= 10;
		ll x = (y / z_pow) % 10;

		ll p_pow = 1;
		for (ll j = 0; j < p; j++) p_pow *= 10;

		if (x >= 5) {
			y += p_pow;
			y /= p_pow;
			y *= p_pow;
		}
		else {
			y /= p_pow;
			y *= p_pow;
		}
	}
	return y;
};
ll b_round(ll i) {
	ll q_pow = 1;
	ll b = 0;
	while (q_pow <= i) {
		q_pow *= 10;
		b++;
	}
	ll b_pow = 1;
	for (ll j = 0; j < b - 1; j++) {
		b_pow *= 10;
	}
	ll x = (i / b_pow) % 10;

	b_pow = 1;
	for (ll j = 0; j < b; j++) {
		b_pow *= 10;
	}

	ll rounded = i;
	if (x >= 5) {
		rounded += b_pow;
		rounded /= b_pow;
		rounded *= b_pow;
	}
	else {
		rounded /= b_pow;
		rounded *= b_pow;
	}
	return rounded;
};
int main() {
	ll t;
	cin >> t;
	for (ll j = 0; j < t; j++) {
		ll n;
		cin >> n;
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		ll count = 0;
		for (ll i = 2; i <= n; i++) {
			ll b = b_round(i), e = e_round(i);
			if (b != e) {
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
