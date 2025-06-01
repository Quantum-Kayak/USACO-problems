#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <deque>
#include <bitset>
#include <cmath>

using namespace std;

// Fast IO for USACO file problems
void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// Type aliases
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vb = vector<bool>;

// Helpful macros
#define pb push_back
#define all(x) x.begin(), x.end()

// Debugging helper (turn off before submission!)
#define dbg(x) cerr << #x << " = " << (x) << endl;

int main() {
    unordered_map<ll, ll> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b;
        if (a == 0) {
            cin >> c;
            arr[b] = c;
        }
        else {
            cout << arr[b] << endl;
        }
        
    }
    return 0;
}
