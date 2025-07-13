# 🌳 BFS and DFS in Segment Trees (C++ Edition)

Let’s be honest: Segment Trees are already more niche than your average binary tree, and using **BFS** or **DFS** directly isn’t a standard practice for them. However, let’s pretend you’re determined to do it anyway, because why not?

---

## ⚙️ Segment Tree Recap

A **segment tree** is a binary tree that helps you:
- Quickly find **range queries** (like sum, min, max in a range).
- Do **range updates** efficiently.

Each node represents a segment or interval of an array.

---

## 🔍 DFS in Segment Trees

**DFS** (Depth-First Search) is basically what you do naturally when you build or update a segment tree. Here’s a basic **build** function that *accidentally* does DFS:

```cpp
void build(int node, int start, int end, int arr[], int tree[]) {
    if (start == end) {
        // Leaf node
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        // Build left subtree
        build(2*node, start, mid, arr, tree);
        // Build right subtree
        build(2*node+1, mid+1, end, arr, tree);
        // Merge the results
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
```
Here, we:

Recursively visit left and right children (DFS, baby!).

Build the tree bottom-up.

## 🌊 BFS in Segment Trees
BFS (Breadth-First Search) would mean level-order traversal. Usually, you don’t need this for segment trees because they’re for range queries/updates. But, if you absolutely insist:
```cpp
#include <queue>

void bfs(int tree[], int n) {
    std::queue<int> q;
    q.push(1); // assuming tree[1] is the root

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        std::cout << "Node " << node << ": " << tree[node] << std::endl;

        int left = 2*node;
        int right = 2*node + 1;

        if (left < n) q.push(left);
        if (right < n) q.push(right);
    }
}
```
## 🧪 Complete Example
Here’s a full (but minimalist) segment tree example with DFS (build) and optional BFS (traversal):
```cpp
#include <iostream>
#include <queue>

const int MAXN = 1e5;
int tree[4*MAXN];
int arr[MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void bfs(int n) {
    std::queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        std::cout << "Node " << node << ": " << tree[node] << std::endl;

        int left = 2*node;
        int right = 2*node+1;

        if (left < 4*n) q.push(left);
        if (right < 4*n) q.push(right);
    }
}

int main() {
    int n = 5;
    for (int i = 0; i < n; i++) arr[i] = i+1;

    build(1, 0, n-1);

    std::cout << "BFS traversal of segment tree:" << std::endl;
    bfs(n);

    return 0;
}
```
## 🎯 Conclusion
DFS in segment trees is basically your default recursion.

BFS isn’t standard for segment tree tasks but can be used to check out tree levels, because humans like lists of things.

Happy coding!
