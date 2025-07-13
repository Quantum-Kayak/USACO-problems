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

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (X - a[i] >= 0) {
            X -= a[i];
            ans++;
        } else {
            break; 
        }
    }
    cout << ans;
    return 0;
}
