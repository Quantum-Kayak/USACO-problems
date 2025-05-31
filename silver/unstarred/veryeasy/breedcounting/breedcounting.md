# 🐄 Breed Counting – USACO Silver Division (December 2015)

This directory contains a **C++ solution** to the “Breed Counting” problem from the **USACO 2015 December Silver** contest.

---

## 📜 Problem Summary

Farmer John’s cows are standing in a line, each assigned a breed ID:  
- `1` for Holsteins  
- `2` for Guernseys  
- `3` for Jerseys

Given the breed IDs of `N` cows and `Q` queries, each asking for the count of each breed between positions `a` and `b` (inclusive), determine the number of cows of each breed within each specified range.

---

## 📥 Input Format

- **Line 1:** Two integers `N` and `Q` — the number of cows and the number of queries.  
- **Next `N` lines:** Each line contains an integer `1`, `2`, or `3`, representing the breed ID of a cow.  
- **Next `Q` lines:** Each line contains two integers `a` and `b`, specifying the range for a query.

**Example input:**
6 3
2
1
1
3
2
1
1 6
3 3
2 4

---

## 📤 Output Format

For each query, output three integers: the number of Holsteins, Guernseys, and Jerseys in the specified range, separated by spaces.

**Example output:**
3 2 1
1 0 0
2 0 1

---

## 💡 Strategy

To efficiently process multiple range queries, we utilize **prefix sums**:

- Maintain three prefix sum arrays: `prefix1`, `prefix2`, and `prefix3`, corresponding to breeds 1, 2, and 3 respectively.
- For each cow, increment the appropriate prefix sum array.
- To answer a query for range `[a, b]`, compute:
  - Holsteins: `prefix1[b] - prefix1[a - 1]`
  - Guernseys: `prefix2[b] - prefix2[a - 1]`
  - Jerseys: `prefix3[b] - prefix3[a - 1]`

This approach allows each query to be answered in constant time after preprocessing.

---

## 🚀 How to Run

```bash
g++ -std=c++17 -o bcount bcount.cpp
./bcount < bcount.in > bcount.out
Ensure that your input file is named bcount.in and the output will be written to bcount.out.
```
## 🧠 Time Complexity
Preprocessing: O(N) — to build the prefix sum arrays.

Each Query: O(1) — constant time using prefix sums.

Total: O(N + Q) — efficient for large values of N and Q (up to 100,000).

## 🔖 Tags
usaco silver prefix_sums range_queries 2015

## 🛠 Why This Exists
To practice efficient range query processing using prefix sums.

To reinforce understanding of cumulative sums in algorithmic problem-solving.

To document the solution approach for future reference and learning.

Happy coding! May your prefix sums always be accurate and your queries swift.
