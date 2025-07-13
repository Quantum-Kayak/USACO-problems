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

int check_win1(int board[3][3]) {
    set<int> solo;

    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            solo.insert(board[i][0]);
    }
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            solo.insert(board[0][i]);
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        solo.insert(board[0][0]);
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        solo.insert(board[0][2]);

    return solo.size();
}

int check_win2(int board[3][3]) {
    set<pair<int, int>> teams;

    auto process = [&](int a, int b, int c) {
        set<int> s = {a, b, c};
        if (s.size() == 2) {
            auto it = s.begin();
            int x = *it++;
            int y = *it;
            if (x > y) swap(x, y);
            teams.insert({x, y});
        }
    };

    for (int i = 0; i < 3; ++i)
        process(board[i][0], board[i][1], board[i][2]);
    for (int i = 0; i < 3; ++i)
        process(board[0][i], board[1][i], board[2][i]);
    process(board[0][0], board[1][1], board[2][2]);
    process(board[0][2], board[1][1], board[2][0]);

    return teams.size();
}

int main() {
    setIO("tttt");
    int board[3][3];
    
    for (int i = 0; i < 3; i++) {
        char a, b , c;
        cin >> a >> b >> c;
        board[i][0] = a;
        board[i][1] = b;
        board[i][2] = c;
    } 
    
    cout << check_win1(board) << endl;
    cout << check_win2(board) << endl;
    return 0;
}
