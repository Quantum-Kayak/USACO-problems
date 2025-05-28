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

#define f first
#define s second
#define all(x) x.begin(), x.end()
typedef long long ll;

int main() {
    int N;
    cin >> N;
    string cows;
    cin >> cows;

    int base_count = 0;
    for (int i = 1; i < N; i += 2) {
        if (cows[i] == 'G') base_count++;
    }

    int max_count = base_count;

    for (int i = 2; i <= N; i += 2) {
        string sliced = cows.substr(0, i);
        reverse(sliced.begin(), sliced.end());
        string new_cows = sliced + cows.substr(i);

        int new_count = 0;
        for (int j = 1; j < N; j += 2) {
            if (new_cows[j] == 'G') new_count++;
        }

        max_count = max(max_count, new_count);
    }

    if (max_count > base_count) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
