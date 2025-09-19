#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] %= m;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            a.push_back(a[i] + m);
        }

        int N = (int)a.size(); // = 2*n
        vector<long long> prefix(N + 1);
        for (int i = 0; i < N; i++) {
            prefix[i+1] = prefix[i] + a[i];
        }

        long long ans = LLONG_MAX;
        for (int l = 0; l < n; l++) {
            int r = l + n - 1;
            int mid = (l + r) / 2;

            long long left_cost = 1LL * a[mid] * (mid - l) - (prefix[mid] - prefix[l]);
            long long right_cost = (prefix[r+1] - prefix[mid+1]) - 1LL * a[mid] * (r - mid);

            long long total_cost = left_cost + right_cost;
            ans = min(ans, total_cost);
        }
        cout << ans << "\n";
    }

    return 0;
}
