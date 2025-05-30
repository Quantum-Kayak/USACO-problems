#include <bits/stdc++.h>
using namespace std;

void setIO(const string &name) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define maxe max_element
#define mine min_element
typedef long long ll;

int main() {
    setIO("bcount"); 
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    vector<long long> prefix1(n + 1, 0);
    vector<long long> prefix2(n + 1, 0);
    vector<long long> prefix3(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> q(Q);
    for (int i = 0; i < Q; i++) {
        cin >> q[i].f >> q[i].s;
    }
    for (int i = 1; i <= n; i++) {
        prefix1[i] = prefix1[i - 1];
        prefix2[i] = prefix2[i - 1];
        prefix3[i] = prefix3[i - 1];
        if (a[i - 1] == 1) prefix1[i]++;
        if (a[i - 1] == 2) prefix2[i]++;
        if (a[i - 1] == 3) prefix3[i]++;
    }
    for (int i = 0; i < Q; i++) {
        int l = q[i].f;
        int r = q[i].s;
        ll p1 = prefix1[r] - prefix1[l - 1];
        ll p2 = prefix2[r] - prefix2[l - 1];
        ll p3 = prefix3[r] - prefix3[l - 1];
        cout << p1 << " " << p2 << " " << p3 << " " << endl;
    }   
    return 0;
}
