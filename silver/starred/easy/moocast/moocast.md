# 🐄 Moocast – USACO Silver (January 2016)

This directory contains a C++ solution to the **"Moocast"** problem from the USACO Silver division.

## 📜 Problem Summary
> Cows are trying to communicate via radio transmissions, because apparently mooing wasn't efficient enough. Each cow can send a message to others within range, determined by its power. The goal is to find the maximum number of cows that can be reached starting from a single cow, using these one-way transmission links. Basically, it’s cow gossip meets graph traversal.

## 📥 Input Format
- The first line contains `n` (1 ≤ n ≤ 200), the number of cows.
- The next `n` lines each contain three integers: `x y p`, representing the cow's location and transmission power.

### Sample Input
4
0 0 1
0 1 1
1 0 1
1 1 1

## 📤 Output Format
- A single integer: the maximum number of cows that can be reached starting from any single cow.

### Sample Output
4

## 💡 Strategy
- Build a **directed graph** where an edge from cow A to B exists if A's transmission can reach B.
- For each cow, perform BFS to count how many cows it can reach.
- Track the maximum value among all BFS runs.

- Edge Cases:
  - Only one cow → answer is 1.
  - Disconnected cows → should only count reachable group.

- Algorithm: BFS on directed graph
- Time complexity: O(n^2) for graph construction + O(n^2) for BFS from each node.

## 🚀 How to Run
```sh
g++ -std=c++17 -o moocast moocast.cpp
./moocast < moocast.in > moocast.out
```
## 🧠 Time Complexity
Break it down cleanly:

Graph construction: O(n^2)

Each BFS: O(n + m), up to O(n^2)

Overall: O(n^3)

## 🔖 Tags
silver medium bfs graph cows moo

silver medium bfs graph cows moo
### 🛠 Why This Exists
To practice USACO-style competitive programming

To build searchable knowledge of problem-solving patterns

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

Happy coding. May your segments never overflow, and your trees remain acyclic.
