#include <iostream>
#include <vector>

// Number of vertices
const int N = 6;
std::vector<int> adj[N];
bool visited[N];

// Function to add an edge to the graph
void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Undirected graph
}

// DFS traversal from a given node
void dfs(int node) {
    visited[node] = true;
    std::cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    // Adding edges
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    std::cout << "DFS starting from node 0: ";
    dfs(0);

    return 0;
}
