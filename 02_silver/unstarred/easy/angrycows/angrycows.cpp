#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
using namespace std;

bool cancover(const vector<int>& bales, long long r, int k) {
    int n = bales.size();
    int i = 0;
    int cows = 0;
    while (i < n) {
        cows++;
        long long right = (long long)bales[i] + 2*r;
        while (i < n && bales[i] <= right) {
            i++;
        }
        if (cows > k) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> bales(n);
    for (int &x : bales) cin >> x;
    sort(bales.begin(), bales.end());

    long long lo = 0, hi = 1'000'000'000, ans = hi;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (cancover(bales, mid, k)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
