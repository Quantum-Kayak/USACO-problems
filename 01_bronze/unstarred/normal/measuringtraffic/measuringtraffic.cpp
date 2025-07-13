#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cmath>
#include <climits>
#include <iomanip>
#include <cassert>
#include <fstream>
#include <bitset>
#include <numeric>

using namespace std;

// Type aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vpi = vector<pii>;
using vpl = vector<pll>;

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;

// Constants
const ll INF = 1e18;
const int MX = 1001;   // adjust per problem constraints

// Fast IO
void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// Debug (remove or disable before submitting)
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define dbg2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << '\n';

// Macros
#define pb push_back
#define all(x) x.begin(), x.end()
#define f first
#define s second

struct seg {
    string type;
    int low, high;
};

int main() {
    setIO("traffic");  // Replace with actual filename
    int n, low = 0, high = MX;
    cin >> n;
    vector<seg> road(n);
    
    for (int i = 0; i < n; i++) {
        cin >> road[i].type >> road[i].low >> road[i].high;
    }
    
    for (int i = n - 1; i >= 0; --i) {
        auto& seg = road[i];
    
        if (seg.type == "off") {
            low += seg.low;
            high += seg.high;
        } else if (seg.type == "on") {
            low = max(0, low - seg.high);
            high -= seg.low;
        } else {
            low = max(low, seg.low);
            high =min(high, seg.high);
        }
    }
    
    int blow = low, bhigh = high;
    low = 0;
    high = MX;
    
    for (int i = 0; i < n; ++i) {
        auto& seg = road[i];
    
        if (seg.type == "on") {
            low += seg.low;
            high += seg.high;
        } else if (seg.type == "off") {
            low = max(0, low - seg.high);
            high -= seg.low;
        } else {
            low = max(low, seg.low);
            high = min(high, seg.high);
        }
    }
    
    cout << blow << " " << bhigh << "\n";
    cout << low << " " << high << "\n";
    return 0;
}
