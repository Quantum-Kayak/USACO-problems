# 🌱 grassplanting – USACO Bronze Problem (February 2019)

This repository contains a C++ solution to the **"Grass Planting"** problem from the USACO Bronze division.

## 🐄 Problem Summary

Farmer John has built a network of `N` fields connected by `N-1` bidirectional paths, forming a tree. He wants to plant grass along each of the paths, but to keep things interesting (and prevent the grass from feeling like it's in a monoculture), he insists that no two paths sharing a field are planted with the same type of grass.

Your task is to compute the *minimum number of grass types* required so that no two adjacent paths share the same type.

## 📥 Input

- First line: An integer `N` — the number of fields (2 ≤ N ≤ 100,000)
- Next `N-1` lines: Each line contains two integers `u` and `v` indicating a path between fields `u` and `v`.

**Example Input (planting.in):**
4
1 2
1 3
1 4

## 📤 Output

- A single integer — the minimum number of grass types needed.

**Example Output (planting.out):**
3

## 💡 Approach

This is a classic graph coloring problem... except you’re coloring edges (paths) instead of nodes (fields). But there’s a sneaky trick:

- Since the graph is a tree (no cycles), the worst-case overlap of paths at any field is equal to the *maximum degree* (i.e., the field connected to the most paths).
- Therefore, the **minimum number of grass types** needed is simply the **maximum degree + 1**.

### Breakdown:
- Read the graph as an adjacency list.
- Track the degree (number of connections) of each node.
- Find the node with the highest degree.
- Add 1 to that degree to get your answer.

🥱 It’s not rocket science. It’s grass science.

## 📁 Files

- `planting.cpp` – C++ source code implementing the solution.
- `planting.in` / `planting.out` – Standard USACO input/output files.
- `README.md` – You're here, basking in the chlorophyll-scented glory.

## 🚀 How to Run

Make sure your compiler isn't still stuck in the Ice Age:

```bash
g++ -std=c++17 -O2 -o planting planting.cpp
./planting < planting.in > planting.out
Or submit it to the USACO grader and wait for your participation ribbon.
```
## 🧠 Time Complexity
Reading and processing: O(N)

Finding max degree: O(N)

Total: O(N) — Efficient even if Farmer John suddenly decides to build 100,000 fields because therapy is expensive.

## 🌾 Notes
The solution uses freopen-style file I/O, as required by USACO.

No fancy data structures needed — just arrays, vectors, and the crushing weight of algorithmic inevitability.

Nature is healing. The fields are connected. The grass is... distinct.

Happy planting!
