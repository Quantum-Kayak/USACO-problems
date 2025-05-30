#include <bits/stdc++.h>
using namespace std;

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
#define dbg(x) cerr << #x << " = " << (x) << endl;

int main() {

    int N, Q;
    cin >> N >> Q;

    vll a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vll prefix(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l] << '\n';
    }

    return 0;
}
