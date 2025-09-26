#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    int n; 
    cin >> n;

    vector<int> elsie(n);
    vector<bool> isElsie(2 * n + 1, false);

    for (int &x : elsie) {
        cin >> x;
        isElsie[x] = true;
    }

    vector<int> bessie;
    for (int i = 1; i <= 2 * n; ++i) {
        if (!isElsie[i]) {
            bessie.push_back(i);
        }
    }

    sort(elsie.begin(), elsie.end());
    sort(bessie.begin(), bessie.end());

    int wins = 0;
    int j = 0;

    for (int i = 0; i < n && j < n; ++i) {
        while (j < n && bessie[j] <= elsie[i]) {
            ++j;
        }
        if (j < n) {
            ++wins;
            ++j;
        }
    }

    cout << wins << '\n';
    return 0;
}
