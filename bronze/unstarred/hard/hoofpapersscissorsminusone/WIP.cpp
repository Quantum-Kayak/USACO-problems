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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> rs(n, vector<char>(n));
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        for (int j = 0; j <= i; j++) {
            rs[i][j] = line[j];
            if (j != i) {
                rs[j][i] = (line[j] == 'W' ? 'L' : (line[j] == 'L' ? 'W' : 'D'));
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int e1, e2;
        cin >> e1 >> e2;
        e1--; e2--;

        int count = 0;
        for (int L = 0; L < n; L++) {
            for (int R = 0; R < n; R++) {
                if (
                    (rs[L][e1] == 'W' || rs[R][e1] == 'W') &&
                    (rs[L][e2] == 'W' || rs[R][e2] == 'W')
                ) {
                    count++;
                }
            }
        }
        cout << count << '\n';
    }

    return 0;
}
