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

int main() {
    setIO("gymnastics");
    int K, N;
    cin >> K >> N;
    vector<vector<int>> ranks(K, vector<int>(N));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ranks[i][j];
        }
    }

    int tot = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            bool i_better = true;
            for (int s = 0; s < K; s++) {
                int pos_i = find(ranks[s].begin(), ranks[s].end(), i) - ranks[s].begin();
                int pos_j = find(ranks[s].begin(), ranks[s].end(), j) - ranks[s].begin();
                if (pos_i > pos_j) {
                    i_better = false;
                    break;
                }
            }
            if (i_better) tot++;
        }
    }
    cout << tot << endl;
    return 0;
}
