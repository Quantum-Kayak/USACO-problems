#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> children(n);
    for (int &p : children) {
        cin >> p;
    }
    int g = 0;
    sort(children.begin(), children.end());
    int i = 0;
    int j = n - 1;

    while (i <= j) {
        if (children[j] + children[i] >= x) {
            i++;
        }
        j++;
        g++;
    }
    cout << g;
    return 0;
}
