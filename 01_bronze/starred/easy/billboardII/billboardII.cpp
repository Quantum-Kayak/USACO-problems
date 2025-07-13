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

// Type Aliases
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

// Constants
const ll INF = 1e18;
const int MX = 2e5 + 5;

// Fast IO for USACO
void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// Debugging Macros
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#define dbg2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << '\n'

// Debug for vectors
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (int i = 0; i < (int)v.size(); ++i)
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    return os << "]";
}

#define dbg(x) cerr << #x << " = " << (x) << '\n'


// Binary Search Helpers
template <typename T>
int lb(const vector<T>& v, T val) {
    return lower_bound(v.begin(), v.end(), val) - v.begin();
}
template <typename T>
int ub(const vector<T>& v, T val) {
    return upper_bound(v.begin(), v.end(), val) - v.begin();
}

// Shortcuts
#define pb push_back
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define sz(x) (int)(x).size()
#define each(a, x) for (auto& a : x)

	struct Rect{
    int x1,y1,x2,y2;
    int area(){
        return (x2-x1)*(y2-y1);
    }
};
int Rectoverlap(Rect a , Rect b){
    int width = max(0,min(a.x2,b.x2) - max(a.x1,b.x1));
    int height = max(0,min(a.y2,b.y2) - max(a.y1,b.y1));
    if ((width < (a.x2-a.x1) && height < (a.y2 - a.y1)) || (b.x1 > a.x1 && b.x2 < a.x2) || (b.y1 > a.y1 && b.y2 < a.y2)){
        return 0;
    }
    return width * height;
}
int main(){
    setIO("billboard");
    Rect lawnmower, remaingrass;
    cin >> lawnmower.x1 >> lawnmower.y1 >> lawnmower.x2 >> lawnmower.y2;
    cin >> remaingrass.x1 >> remaingrass.y1 >> remaingrass.x2 >> remaingrass.y2;
    int ans = lawnmower.area() - Rectoverlap(lawnmower,remaingrass);
    cout << ans << endl;
}
