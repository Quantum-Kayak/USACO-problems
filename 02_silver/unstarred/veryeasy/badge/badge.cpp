#include <bits/stdc++.h>
using namespace std;

// Fast IO for USACO file problems
void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// Type aliases
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// Helpful macros
#define pb push_back
#define all(x) x.begin(), x.end()

// Debugging helper (turn off before submission!)
#define dbg(x) cerr << #x << " = " << (x) << endl;

vi ans;
vector<bool> visited;
vi p;
void dfs(int a) {
    if (visited[a]) {
        cout << a << " ";
        return;
    }
    visited[a] = true;
    dfs(p[a]);
}
int main() {
    int n;
    cin >> n;
    visited.resize(n + 1);
    p.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        dfs(i);
    }
    return 0;
}
