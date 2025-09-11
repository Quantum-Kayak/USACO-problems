#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int MAXN = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int,int>> ranges;
    {
        long long low = 45, high = 49;
        while (low <= MAXN) {
            ranges.push_back({(int)low, (int)min<long long>(high, MAXN)});
            low  = low  * 10 - 5;
            high = high * 10 + 9;
        }
    }

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; 
        cin >> N;

        long long ans = 0;
        for (auto [L, R] : ranges) {
            if (L > N) break;
            int a = max(L, 2);
            int b = min(R, N);
            if (a <= b) ans += (b - a + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
