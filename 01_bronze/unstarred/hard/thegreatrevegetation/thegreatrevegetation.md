# 🐄 The Great Revegetation – USACO Silver (December 2019)

This directory contains a C++ solution to the **"The Great Revegetation"** problem (`revegetate`) from the USACO Silver division.

## 📜 Problem Summary
> Farmer John wants to plant grass types (1–4) in `n` fields connected by `m` paths. Adjacent fields must have **different grass types**, and FJ wants the final layout interpreted as a **concatenated digit sequence** to be as small as possible (lexicographically). The task: assign types 1–4 to each field (1 through n) respecting adjacency and lexicographic minimality.

## 📥 Input Format
- Line 1: two integers `n m` — number of fields and adjacency constraints.
- Next `m` lines: two integers `a b` — fields that share a path and must differ.

### Sample Input
4 3
1 2
2 3
2 4

## 📤 Output Format
- A single integer: the **smallest concatenated sequence** of grass types for fields `1…n`.

### Sample Output
1213
## 💡 Strategy
- Treat fields as nodes in an **undirected graph**.
- Use **recursive DFS** to assign grass types from field 1 to n:
  - Try types 1–4 in increasing order.
  - Skip any type already used by a neighbor.
  - Build the result as a decimal sequence: `cur = cur*10 + type`
  - Track the **minimum result** found across valid assignments.
- State-space limited enough for `n ≤ 100` and small degree graphs.

- Time Complexity:
  - Exponential in worst case, but short paths + small constraints make it feasible within input limits.

## 🚀 How to Run
```sh
g++ -std=c++17 -o revegetate revegetate.cpp
./revegetate < revegetate.in > revegetate.out
```
## 🧠 Time Complexity
Break it down:

DFS from field 1 to n

At each node: up to 4 trials × average few neighbors → manageable for n ≤ 100

Overall: effectively ~O(4^n × deg), but input constraints keep it fast enough

### 🔖 Tags
silver graph coloring dfs lexicographic min recursion fields

## 🛠 Why This Exists
To practice DFS with pruning and lexicographic state tracking

To build searchable knowledge of coloring and order optimization

To archive the puzzles I solved—each with its own cow‑shaped storyline

May your fields stay fresh, your colors clash neatly, and your strings never overflow integer limits.
