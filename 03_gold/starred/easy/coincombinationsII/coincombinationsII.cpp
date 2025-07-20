#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    vector<int> coins(a);
    for (int i = 0; i < a; ++i) cin >> coins[i];

    vector<int> dp(b + 1);
    dp[0] = 1;
    for (int c : coins)
        for (int i = c; i <= b; ++i)
            dp[i] = (dp[i] + dp[i - c]) % MOD;

    cout << dp[b] << '\n';
    return 0;
}
