#include <iostream>
#include <vector>
#include <queue>

// Number of vertices
const int N = 6;
std::vector<int> adj[N];
bool visited[N];

// Function to add an edge to the graph
void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Undirected graph
}

// BFS traversal from a given start node
void bfs(int start) {
    std::queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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

    std::cout << "BFS starting from node 0: ";
    bfs(0);

    return 0;
}
