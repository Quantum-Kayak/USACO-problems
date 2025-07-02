# 🐄 Fence Planning – USACO Silver (February 2016)

This directory contains a C++ solution to the **"Fence Planning"** problem from the USACO Silver division.

## 📜 Problem Summary
> Cows are hanging out in a pasture, but only in small cliques. Each cow has a position on a 2D grid, and some pairs of cows are friends. Friendship is mutual and transitive, and cows that are connected (directly or indirectly) form a single group. Farmer John wants to build a rectangular fence around **one entire group**, using the **smallest possible amount of fencing** (i.e., the perimeter). Your goal is to compute the **minimum perimeter** required to fence in any one of these cow clusters.

## 📥 Input Format
- Line 1: Two integers `N` and `M` — number of cows and friendships.
- Lines 2 to `N+1`: Two integers per line, the `(x, y)` coordinates of each cow.
- Next `M` lines: Each contains two integers `a` and `b`, indicating a friendship between cow `a` and cow `b`.

### Sample Input
5 3
1 1
2 2
3 3
10 10
11 11
1 2
2 3
4 5

## 📤 Output Format
- A single integer: the **minimum perimeter** required to enclose a connected group of cows.

### Sample Output
8

## 💡 Strategy
- Model cows and friendships as an **undirected graph**.
- Traverse each **connected component** using BFS.
- Track `minX`, `maxX`, `minY`, `maxY` of each group to calculate the bounding rectangle.
- For each component, compute the perimeter `2 * (width + height)`.
- Track and return the **minimum** of all component perimeters.

- Time Complexity:
  - Graph construction: O(M)
  - Traversal of each component: O(N + M)

## 🚀 How to Run
```sh
g++ -std=c++17 -o fenceplan fenceplan.cpp
./fenceplan < fenceplan.in > fenceplan.out
```
## 🧠 Time Complexity
Break it down cleanly:

Building graph: O(M)

Component traversal: O(N + M)

Overall: O(N + M)

### 🔖 Tags
silver bfs graph geometry components perimeter friendzone

silver bfs graph geometry components perimeter friendzone
## 🛠 Why This Exists
To practice USACO-style competitive programming

To build searchable knowledge of problem-solving patterns

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your friendships be transitive, your fences efficient, and your coordinates never escape the grid.
