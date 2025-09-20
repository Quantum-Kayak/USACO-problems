#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long t;
    cin >> n >> t;

    vector<long long> k(n);
    for (long long &x : k) cin >> x;

    long long low = 0;
    long long high = 1e18;
    long long ans = high;

    while (low <= high) { 
        long long mid = (low + high) / 2;
        long long product = 0;

        for (long long machine : k) {
            product += mid / machine;
            if (product >= t) break;
        }

        if (product >= t) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
