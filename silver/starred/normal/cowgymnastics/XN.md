# 🐄 Explanation of `gymnastics.cpp`

This C++ program determines how many pairs of cows maintain a consistent ranking order across multiple training sessions.  
It reads from `gymnastics.in` and writes the result to `gymnastics.out`.

The task is to count all pairs `(a, b)` such that cow `a` always ranks higher than cow `b` in **every** session.

---

## 📦 Includes and Setup

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
```

**Explanation:**  
- Standard C++ headers for I/O, containers, and algorithms.  
- `set` is included but never used. You can remove it unless you're clinging to it like emotional baggage.

---

## 📂 File Redirection and I/O Optimization

```cpp
#define PROBLEM_NAME "gymnastics"
freopen((string(PROBLEM_NAME) + ".in").c_str(), "r", stdin);
freopen((string(PROBLEM_NAME) + ".out").c_str(), "w", stdout);

ios::sync_with_stdio(false);
cin.tie(nullptr);
```

**Explanation:**  
- Reads input from `gymnastics.in` and writes output to `gymnastics.out`.  
- Speeds up input/output by disabling synchronization with C-style I/O.  
- `cin.tie(nullptr)` prevents `cin` from automatically flushing `cout`, which is totally cool if you like performance.

---

## 📥 Reading Input

```cpp
int K, N;
cin >> K >> N;
vector<vector<int>> sessions(K, vector<int>(N));
vector<vector<int>> position(K, vector<int>(N + 1));
```

**Explanation:**  
- `K`: Number of sessions (training rounds).  
- `N`: Number of cows.  
- `sessions`: Stores the ranking order of cows in each session.  
- `position[k][cow]`: Stores the rank (index) of `cow` in session `k`.

```cpp
for (int k = 0; k < K; ++k) {
    for (int rank = 0; rank < N; ++rank) {
        int cow;
        cin >> cow;
        sessions[k][rank] = cow;
        position[k][cow] = rank;
    }
}
```

**Explanation:**  
- For each session, reads the cow rankings and saves their position.  
- 0-indexed, because this is C++ and we like pain.

---

## 🔢 Counting Consistent Pairs

```cpp
int count = 0;

for (int a = 1; a <= N; ++a) {
    for (int b = 1; b <= N; ++b) {
        if (a == b) continue;

        bool consistent = true;

        for (int k = 0; k < K; ++k) {
            if (position[k][a] > position[k][b]) {
                consistent = false;
                break;
            }
        }

        if (consistent) count++;
    }
}
```

**Explanation:**  
- Loops through all pairs of distinct cows `(a, b)`.  
- For each pair, checks if `a` always ranked higher than `b`.  
- If true for **all** sessions, increments the counter.

---

## 📤 Output

```cpp
cout << count << endl;
```

**Explanation:**  
Prints the total number of consistent cow pairs. Moo.

---

## 🧮 Summary

- **Time Complexity:** `O(N² * K)` — tolerable unless you hate efficiency.  
- **Space Complexity:** `O(K * N)` — perfectly fine unless you're storing cows in RAM.

Suitable for small constraints like those found in beginner competitive programming problems. Or cow-themed hackathons.

