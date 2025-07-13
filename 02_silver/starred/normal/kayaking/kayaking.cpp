#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int best = 1e9;
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = i + 1; j < 2 * n; ++j) {
            vector<int> b;
            for (int k = 0; k < 2 * n; ++k) {
                if (k != i && k != j) b.push_back(a[k]);
            }

            int curr = 0;
            for (int k = 0; k < b.size(); k += 2) {
                curr += b[k + 1] - b[k];
            }

            best = min(best, curr);
        }
    }

    cout << best << '\n';
    return 0;
}

