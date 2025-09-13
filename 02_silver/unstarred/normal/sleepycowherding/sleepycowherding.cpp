#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }

    sort(pos.begin(), pos.end());

    int max_ = max((pos[n-2] - pos[0] + 1) - (n-1), (pos[n-1] - pos[1] + 1) - (n-1));
    int min = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j+1 < n && pos[j+1] - pos[i] < n) {
            j++;
        }
        min = max(min, j - i + 1);
    }
    min = n - min;
    if (min == 1 &&
    ((pos[n-2] - pos[0] == n-2 && pos[n-1] - pos[n-2] > 2) ||
        (pos[n-1] - pos[1] == n-2 && pos[1] - pos[0] > 2))) {
        min = 2;
    }

    cout << min << "\n";
    cout << max_;
}
