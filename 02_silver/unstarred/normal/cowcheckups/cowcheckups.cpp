#include <iostream>     // Standard I/O
#include <vector>       // std::vector
#include <queue>        // std::queue
#include <set>          // std::set
#include <map>          // std::map
#include <unordered_map>// std::unordered_map
#include <algorithm>    // std::sort, std::max, std::min
#include <cmath>        // std::abs, std::sqrt, etc
#include <string>       // std::string
#include <sstream>      // std::stringstream
#include <stack>        // std::stack
#include <bitset>       // std::bitset
#include <climits>      // INT_MAX, INT_MIN
#include <cfloat>       // DBL_MAX, etc.
#include <cstring>      // memset
#include <cassert>      // assert
#include <numeric>      // std::iota, std::accumulate
#include <functional>   // std::function
#include <iomanip>      // std::setprecision
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i) cin >> b[i];

    /* positions of every species in the two arrays */
    vector<vector<int>> posA(N + 1), posB(N + 1);
    for (int i = 1; i <= N; ++i) {
        posA[a[i]].push_back(i);
        posB[b[i]].push_back(i);
    }

    const ll totIntervals = 1LL * N * (N + 1) / 2;   // N(N+1)/2
    ll ans = 0;

    /* ----------  case A – intervals NOT covering i  ---------- */
    for (int i = 1; i <= N; ++i)
        if (a[i] == b[i])
            ans += totIntervals - 1LL * i * (N - i + 1);

    /* ----------  case B – both i & j are reversed  ----------- */
    for (int v = 1; v <= N; ++v) {
        const auto &A = posA[v];
        const auto &B = posB[v];
        if (A.empty() || B.empty()) continue;

        const int m = static_cast<int>(A.size());

        /* prefix sums of positions in A for O(1) range‑sums */
        vector<ll> pref(m + 1, 0);
        for (int k = 0; k < m; ++k) pref[k + 1] = pref[k] + A[k];
        const ll sumAll = pref[m];

        for (int i : B) {
            int T = N - i;                      // boundary between the two cases

            int idx_i = lower_bound(A.begin(), A.end(), i) - A.begin(); // first j ≥ i
            int idx_T = upper_bound(A.begin(), A.end(), T) - A.begin(); // first j > T

            /* ---- four disjoint ranges of j ---- */
            int cnt1 = min(idx_i, idx_T);                      // j ≤ T  and  j <  i
            ll  sum1 = pref[cnt1];                             //   contributes      j

            int cnt2 = max(0, idx_T - idx_i);                 // j ≤ T  and  j ≥ i
            ll  sum2 = 1LL * cnt2 * i;                        //   contributes      i

            int cnt3 = max(0, idx_i - idx_T);                 // j > T  and  j <  i
            ll  sum3 = 1LL * cnt3 * (N - i + 1);              //   contributes   N-i+1

            int cut   = max(idx_i, idx_T);                    // first index of range‑4
            int cnt4  = m - cut;                              // j > T  and  j ≥ i
            ll  sumJ4 = sumAll - pref[cut];
            ll  sum4  = 1LL * cnt4 * (N + 1) - sumJ4;         //   contributes   N-j+1

            ans += sum1 + sum2 + sum3 + sum4;
        }
    }

    cout << ans << '\n';
    return 0;
}
