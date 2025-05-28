# 🧠 planting.cpp – Deep Dive Explanation

This is a detailed walkthrough of the logic and inner workings of `planting.cpp`, a C++ solution to the **USACO Bronze** problem "Grass Planting."

The goal? Plant different types of grass on edges of a tree such that no two edges incident to the same node share the same type. You know — botanical diversity, but for graphs.

---

## 🔢 Problem Recap

- We’re given a **tree** with `N` nodes and `N-1` edges.
- Each edge connects two fields.
- Grass types are like colors: no two edges sharing a node can have the same grass.
- Determine the *minimum number of grass types* needed.

---

## 📦 File: `planting.cpp`

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
```
Brings in standard headers.

fstream is used for file I/O, because this is USACO and stdin is for amateurs.

using namespace std;
Classic move. Now you don’t have to type std:: like some kind of verbose robot.

```cpp
int main() {
    ifstream fin("planting.in");
    ofstream fout("planting.out");
```
Standard USACO boilerplate.

Redirects input and output from files named planting.in and planting.out.
```cpp
    int N;
    fin >> N;
```
Reads in the number of nodes (aka fields).

Since it’s a tree, the number of edges is N - 1.
```cpp
    vector<int> adj[N + 1];
```
Declares an adjacency list.

adj[i] will store the neighbors of node i.

Using N+1 for 1-based indexing, because zero-based nodes are for soulless data structures.
```cpp
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
```
Loops over each edge.

Each edge connects two nodes u and v, and since the tree is undirected, we add each to the other's list.
```cpp
    int maxDegree = 0;
```
Tracks the maximum degree — the number of edges connected to any single node.

This tells us how many conflicts we might have at worst.
```cpp
    for (int i = 1; i <= N; i++) {
        int degree = adj[i].size();
        if (degree > maxDegree) {
            maxDegree = degree;
        }
    }
```
Loops over all nodes.

adj[i].size() gives the number of connections (degree) of node i.

Updates maxDegree to the highest value seen.
```cpp
    fout << maxDegree + 1 << '\n';
```
The actual answer: max degree + 1.

Why? Because each node can have up to maxDegree edges touching it, and each must be a different type. So we need one more type than the worst case.
```cpp
    return 0;
}
```
Obligatory happy ending for main.
