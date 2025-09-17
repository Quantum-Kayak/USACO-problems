#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> prefix(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    prefix[0] = 0;

    for (int i = 1; i < n; i++) {
        prefix[i] += a[i] + prefix[i - 1] + a[0];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prefix[i] - prefix[j] == n) {
                 ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
