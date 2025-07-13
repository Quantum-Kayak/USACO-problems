# 🕸️ Graphs in C++

A **graph** is a data structure consisting of:
- **Vertices (nodes)**: Points.
- **Edges (connections)**: Links between the points.

Graphs can be:
- **Directed** (edges have a direction) or **undirected** (edges are mutual).
- **Weighted** (edges have weights) or **unweighted** (edges are just edges, no extra baggage).

---

## ⚙️ Graph Representations

### 1️⃣ Adjacency Matrix

A 2D array `matrix[N][N]`:
- `matrix[i][j] = 1` if there’s an edge from `i` to `j`.
- Works well for small graphs.

Example:

```cpp
const int N = 4;
int matrix[N][N] = {0};

// Edge from 0 to 1
matrix[0][1] = 1;
// Edge from 1 to 2
matrix[1][2] = 1;
// Undirected? Make it symmetrical
matrix[1][0] = 1;
```
2️⃣ Adjacency List
A more space-efficient representation:

Array (or vector) of lists.

Example:

#include <iostream>
#include <vector>

const int N = 4;
std::vector<int> adj[N];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // If undirected
}
🔍 Graph Traversal
📌 Depth-First Search (DFS)
DFS goes as deep as possible before backtracking.
```cpp
#include <iostream>
#include <vector>

const int N = 4;
std::vector<int> adj[N];
bool visited[N];

void dfs(int node) {
    visited[node] = true;
    std::cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
```
## 📌 Breadth-First Search (BFS)
BFS explores level by level.
```cpp
#include <iostream>
#include <vector>
#include <queue>

const int N = 4;
std::vector<int> adj[N];
bool visited[N];

void bfs(int start) {
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
```
## 🧪 Putting It All Together
A tiny example:
```cpp
#include <iostream>
#include <vector>
#include <queue>

const int N = 4;
std::vector<int> adj[N];
bool visited[N];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Undirected
}

void dfs(int node) {
    visited[node] = true;
    std::cout << node << " ";
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) dfs(neighbor);
    }
}

void bfs(int start) {
    std::queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);

    std::cout << "DFS: ";
    dfs(0);

    // Reset for BFS
    std::fill(visited, visited+N, false);
    std::cout << "\nBFS: ";
    bfs(0);

    return 0;
}
```
## 🎯 Conclusion
Graphs in C++ are just a bunch of nodes hanging out together. Once you understand adjacency lists, DFS, and BFS, you’re basically ready to start using graphs to solve actual problems—like navigating social networks or realizing you have no social life.

Enjoy!
