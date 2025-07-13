# 🌐 Connected Components Counter – Competitive Programming Practice

This directory contains a C++ solution to a **connected components** counting problem in an undirected graph. You know, the kind of thing that shows up in random contests or your nightmares.

## 📜 Problem Summary
> Given a graph with `n` nodes and `m` edges, determine the number of connected components in the graph. A connected component is a set of nodes such that every node in the set can reach every other node in the set.

## 📥 Input Format
- The first line contains two integers: `n` (number of nodes) and `m` (number of edges).
- The next `m` lines each contain two integers `a` and `b`, representing an undirected edge between nodes `a` and `b`.

### Example Input
5 3
1 2
2 3
4 5

## 📤 Output Format
- A single integer: the number of connected components.

### Example Output
2

## 💡 Strategy
- Build an adjacency list for the graph.
- Use Depth First Search (DFS) to explore each connected component.
- Count the number of times you start a new DFS traversal — each time represents a new connected component.

### Key Observations
- The graph is **undirected** — so edges go both ways.
- DFS marks all nodes in a connected component as visited.
- By repeating the DFS from unvisited nodes, you find all the separate components.

---

### 🧠 Time Complexity
- Building the adjacency list: **O(m)**
- DFS traversal for all nodes: **O(n + m)**
- Overall: **O(n + m)**, which is perfectly fine unless your input is the internet itself.

---

## 🚀 How to Run
```sh
g++ -std=c++17 -o components components.cpp
./components < input.txt > output.txt
```
## 🔖 Tags
graph search, dfs, connected components, competitive programming, adjacency list, mild confusion

## 🛠 Why This Exists
To practice graph search algorithms in competitive programming.

To learn how to count things besides the number of times you question life choices.

To avoid writing dfs from scratch every single time — just copy/paste this and move on.

Happy coding! If your graph’s components start talking to each other, you might want to check your code.
