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

const int MAXN = 3e5 + 13;

int N;
string s;
int arr[MAXN];
int eG, eH;
int lG, lH;
int ans;

int main() {
    cin >> N >> s;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i]--;
    }
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'G')
        {
            eG = i;
            break;
        }
    }
    for (int i = N - 1; i >= 0; i--)
    {
        if (s[i] == 'G')
        {
            lG = i;
            break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'H')
        {
            eH = i;
            break;
        }
    }
    for (int i = N - 1; i >= 0; i--)
    {
        if (s[i] == 'H')
        {
            lH = i;
            break;
        }
    }
    if (arr[eG] >= lG)
    {
        for (int i = 0; i < eG; i++)
        {
            if (i == eH)
            {
                continue;
            }
            if (s[i] == 'H' && arr[i] >= eG)
            {
                ans++;
            }
        }
    }
    if (arr[eH] >= lH)
    {
        for (int i = 0; i < eH; i++)
        {
            if (i == eG)
            {
                continue;
            }
            if (s[i] == 'G' && arr[i] >= eH)
            {
                ans++;
            }
        }
    }
    if ((arr[eG] >= lG || (eG <= eH && arr[eG] >= eH)) && (arr[eH] >= lH || (eH <= eG && arr[eH] >= eG)))
    {
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
