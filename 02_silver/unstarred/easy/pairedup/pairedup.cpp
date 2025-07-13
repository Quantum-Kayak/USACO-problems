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
    setIO("pairup");  // Replace with actual filename
    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i].second >> cows[i].first;
    }
    sort(all(cows));
    
    int i = 0, j = n - 1;
    int answer = 0;
    while (i <= j) {
        int pairs = min(cows[i].second, cows[j].second);
        if (i == j) pairs /= 2;
        answer = max(answer, cows[i].first + cows[j].first);
        cows[i].second -= pairs;
        cows[j].second -= pairs;
        if (cows[i].second == 0) i++;
        if (cows[j].second == 0) j--;
    }
    cout << answer;
    return 0;
}
