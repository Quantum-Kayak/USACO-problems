# 🐄 Problem Name – USACO Silver (February 2017)

This directory contains a C++ solution to the **"Milk Factory"** problem from the USACO Silver division.

## 📜 Problem Summary
> The cows have built a complicated factory with `n` machines, each pointing to another machine (like a one-way street of conveyor belts). Bessie suspects that there's exactly one “central” machine that can send milk to every other machine. Your job is to figure out if there’s such a machine, and if there is, find it. Otherwise, print `-1` and go back to milking cows.

## 📥 Input Format
- The first line contains a single integer `n` – the number of machines.
- The next `n` lines each contain two integers `a` and `b` (1-indexed) meaning machine `a` sends milk to machine `b`.

### Example Input
4
1 2
2 3
3 4
4 2

## 📤 Output Format
- If there’s exactly one machine that can send milk to all others, print its number.
- Otherwise, print `-1`.

### Example Output
2

## 💡 Strategy
- Reverse the direction of every conveyor belt to get the reversed graph.
- For each machine, check if it can reach every other machine in the reversed graph using DFS.
- If exactly one machine can do this, that’s the central machine.
- If there’s no such machine or multiple candidates, print `-1`.

### Edge Cases
- Disconnected components? No central machine.
- Multiple machines can reach everything? Also no single central machine.
- Single isolated node? It’s itself the central hub.

### Algorithm
1. Build the adjacency list `adj` and the reversed adjacency list `reversed_adj`.
2. For each machine:
   - Use DFS to see if it can reach all others in the reversed graph.
   - If it can, consider it a candidate.
3. If there’s exactly one candidate, print it. Otherwise, print `-1`.

### Time Complexity
- Building the graph: **O(n)**
- DFS for each machine: **O(n²)** (since you do DFS for every node)
- Overall: **O(n²)** – fine for small `n` (USACO problems rarely need more)

---

## 🚀 How to Run
```sh
g++ -std=c++17 -o factory factory.cpp
./factory < factory.in > factory.out
```
## 🔖 Tags
graph search, dfs, reachability, usaco, silver, regret

Happy coding! May your factories never deadlock and your cows always be well-fed.
