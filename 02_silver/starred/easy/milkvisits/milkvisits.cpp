#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");

    int N, M;
    fin >> N >> M;
    string breeds;
    fin >> breeds;

    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        fin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> component(N, -1);
    int component_id = 0;

    // BFS to label components of same-breed connected farms
    for (int i = 0; i < N; i++) {
        if (component[i] == -1) {
            queue<int> q;
            q.push(i);
            component[i] = component_id;
            char breed = breeds[i];
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int neighbor : adj[curr]) {
                    if (component[neighbor] == -1 && breeds[neighbor] == breed) {
                        component[neighbor] = component_id;
                        q.push(neighbor);
                    }
                }
            }
            component_id++;
        }
    }

    string result;
    for (int i = 0; i < M; i++) {
        int a, b;
        char desired;
        fin >> a >> b >> desired;
        --a; --b;
        if (component[a] != component[b]) {
            result += '1';
        } else {
            result += (breeds[a] == desired ? '1' : '0');
        }
    }

    fout << result << '\n';
    return 0;
}
