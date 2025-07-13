#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Compute prefix sums
    vector<ll> prefix(n + 1, 0);  // prefix[0] = 0
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    int max_len = 0;
    int l = 0;
    for (int r = 1; r <= n; r++) {
        // Move l forward if sum exceeds k
        while (l < r && prefix[r] - prefix[l] > k) {
            l++;
        }
        // Valid subarray sum ≤ k
        if (prefix[r] - prefix[l] <= k) {
            max_len = max(max_len, r - l);
        }
    }

    cout << max_len << '\n';
    return 0;
}
