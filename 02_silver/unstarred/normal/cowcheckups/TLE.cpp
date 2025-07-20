#include <iostream>     // Standard I/O
#include <vector>       // std::vector
#include <queue>        // std::queue
#include <set>          // std::set
#include <map>          // std::map
#include <unordered_map>// std::unordered_map
#include <algorithm>    // std::sort, std::max, std::min
#include <cmath>        // std::abs, std::sqrt, etc
#include <string>       // std::string
#include <sstream>      // std::stringstream
#include <stack>        // std::stack
#include <bitset>       // std::bitset
#include <climits>      // INT_MAX, INT_MIN
#include <cfloat>       // DBL_MAX, etc.
#include <cstring>      // memset
#include <cassert>      // assert
#include <numeric>      // std::iota, std::accumulate
#include <functional>   // std::function
#include <iomanip>      // std::setprecision


using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)
#define f first
#define s second

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    int n, tot = 0;
    cin >> n;
    vi cows(n), doc(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> doc[i];
    }
    unordered_map<int, vector<int>> posA, posB;
    for (int i = 0; i < n; i++) {
        posA[cows[i]].push_back(i);
        posB[doc[i]].push_back(i); 
    }

    set<int> cow_species(cows.begin(), cows.end());
    set<int> doc_species(doc.begin(), doc.end());
    set<int> unique_elems;
    for (int s : cow_species) {
        if (doc_species.count(s)) {
            unique_elems.insert(s);
        }
    }

    for (int i = 0; i < n; i++) {
        if (cows[i] == doc[i]) {
            tot += 1; // for the identity operation at i
        }
    }

    for (int s : unique_elems) {
        for (int i : posA[s]) {
            for (int j : posB[s]) {
                if (j != i) {
                    int L = max(0, i + j - (n - 1));
                    int R = min(i, (i + j) / 2);
                    if (L <= R) tot += (R - L + 1);
                }
            }
        }
    }
    cout << tot;
    return 0;
}
