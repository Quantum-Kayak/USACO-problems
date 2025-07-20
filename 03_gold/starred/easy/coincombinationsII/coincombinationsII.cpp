#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int& c : coins) cin >> c;

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int c : coins)
        for (int i = c; i <= x; ++i)
            dp[i] = (dp[i] + dp[i - c]) % MOD;

    cout << dp[x] << "\n";
    return 0;
}
