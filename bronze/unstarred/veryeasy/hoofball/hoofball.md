# 🐄 Hoofball – USACO Silver (December 2017)

This directory contains a C++ solution to the **"Hoofball"** problem from the USACO Silver division.

## 📜 Problem Summary
> Farmer John’s cows have invented a game called "Hoofball," which is like regular ball-passing but with physics replaced by weird nearest-neighbor logic. Each cow passes the ball to its nearest neighbor (breaking ties by going left), and you need to determine the **minimum number of balls** needed so that all cows are involved in passing cycles, chains, or interactions.

## 📥 Input Format
- Line 1: Integer `n` — number of cows.
- Line 2: `n` integers — the positions of the cows along a line.

### Sample Input
5
1 6 8 12 14

## 📤 Output Format
- A single integer: the minimum number of balls required.

### Sample Output
2

## 💡 Strategy
- First, sort cows by position and compute where each one will pass their ball:
  - Each cow sends the ball to the **nearest** cow. Tie-breaker: to the **left**.
- This forms a **directed graph**, where each node (cow) has out-degree 1.
- Count the number of starting points (in-degree 0 cows).
- Handle **2-cycles** (mutual passing pairs) where no one starts but the cycle still exists.
- Sum the number of independent chains and mutual loops for the final answer.

- Time Complexity:
  - Sorting: O(n log n)
  - Graph traversal: O(n)

## 🚀 How to Run
```sh
g++ -std=c++17 -o hoofball hoofball.cpp
./hoofball < hoofball.in > hoofball.out
```
## 🧠 Time Complexity
Break it down cleanly:

Sorting cows by position: O(n log n)

Computing nearest neighbors and simulating pass chains: O(n)

Total: O(n log n)

### 🔖 Tags
silver graphs greedy directed-graph 2-cycles cow-sports
## 🛠 Why This Exists
To practice USACO-style competitive programming

To build searchable knowledge of problem-solving patterns

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your passes never loop endlessly, your cows always face the right direction, and your graphs remain nicely acyclic (unless you're counting 2-cycles, in which case good luck).
