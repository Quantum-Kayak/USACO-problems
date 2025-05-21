#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("planting.in");
    ofstream fout("planting.out");

    int N;
    fin >> N;

    vector<int> adj[N + 1]; 

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

    int maxDegree = 0;

    for (int i = 1; i <= N; i++) {
        int degree = adj[i].size();
        if (degree > maxDegree) {
            maxDegree = degree;
        }
    }

    fout << maxDegree + 1 << '\n';  

    return 0;
}
