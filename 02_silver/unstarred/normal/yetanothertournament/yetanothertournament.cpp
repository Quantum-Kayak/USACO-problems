#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> prep(n);
        for (int i = 0; i < n; i++) {
            cin >> prep[i];
        }

        vector<pair<int,int>> opp;
        for (int i = 0; i < n; i++) {
            opp.push_back({prep[i], i + 1});
        }

        sort(opp.begin(), opp.end());

        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + opp[i - 1].first;
        }

        int answer = n + 1;

        for (int k = 0; k <= n; k++) {
            if (pref[k] <= m) {
                int myWins = k;
                int place = 1;
                for (int i = 0; i < k; i++) {
                    int baseWins = opp[i].second - 1;
                    int finalWins = baseWins - 1; 
                    if (finalWins > myWins) place++;
                }
                for (int i = k; i < n; i++) {
                    int baseWins = opp[i].second - 1;
                    int finalWins = baseWins + 1;
                    if (finalWins > myWins) place++;
                }
                answer = min(answer, place);
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
