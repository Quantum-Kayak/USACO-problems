# 🐄 USACO Problems Repository

Welcome to my archive of solved USACO problems, organized for brutal clarity, long-term reference, and future self-roasting. Each problem includes:

- ✅ A `.cpp` file with the complete solution
- 🧠 A `README.md` (or `.XN.md`) with an explanation, strategy breakdown, and mental notes
- sometimes a `TLE.cpp` cause I was too slow
- 🗂 Sorted by **division**, **difficulty**, and **problem metadata**

---

## 📁 Repository Structure

```text
USACO-problems/
├── bronze/
│   ├── starred/
│   │   ├── easy/
│   │   ├── normal/
│   │   ├── hard/
│   │   └── insane/
│   └── unstarred/
│       ├── easy/
│       ├── normal/
│       ├── hard/
│       └── insane/
├── silver/
│   └── starred/...
├── gold/
│   └── ...
└── plat/
    └── ...
```
## 🎯 Naming Convention

Each problem folder contains:

- `problemname.cpp` → The actual C++ solution  
- `problemname.md` → Writeup and explanation  
- `problemname.XN.md` → If the problem is cursed, deranged, or deserves its own therapy session  

**Examples:**
```text
bronze/starred/easy/blockgame/
├── blockgame.cpp
└── blockgame.md

silver/unstarred/hard/fencedin/
├── fencedin.cpp
└── fencedin.XN.md
```

# 🐄 Problem Name – USACO [Division] ([Month Year])

This directory contains a C++ solution to the **"[Problem Name]"** problem from the USACO [Division] division.

## 📜 Problem Summary
> Your own words summary of what’s going on, who’s angry (usually cows), and what you’re solving.

## 📥 Input Format
- Line-by-line breakdown
- Optional sample input

## 📤 Output Format
- What it prints
- Optional example output

## 💡 Strategy
- Key idea / pattern used
- Edge cases handled
- Algorithm + time complexity

## 🚀 How to Run
```sh
g++ -std=c++17 -o problem problem.cpp
./problem < input.txt > output.txt
```
## 🧠 **Time Complexity**  
Break it down cleanly:

- Reading/expanding segments: O(n + m)  
- Comparison loop: O(100)  
- Overall: O(n + m)
  
🔖 Tags  
division difficulty topics regret

```
division difficulty topics regret
```

---

## 🛠 Why This Exists

- To **practice USACO-style competitive programming**  
- To **build searchable knowledge** of problem-solving patterns  
- To **leave behind a map** for myself (and maybe others) on how I solved — or suffered through — each problem  

---

Happy coding. May your segments never overflow, and your trees remain acyclic.  
---

# USACO template🐮

``` cpp
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
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (int i = 0; i < (int)v.size(); i++)
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    return os << "]";
}

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

int main() {
    setIO("test"); // Change filename as needed
    
    return 0;
}
```
# file is in C:\Users\icody\USACO-problems
