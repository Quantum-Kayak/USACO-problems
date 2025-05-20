#include <iostream>     // cin, cout
#include <vector>       // vector<>
#include <string>       // string, substr, etc.
#include <set>          // set, unordered_set if needed
#include <algorithm>    // sort, min, max, etc.

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    #define PROBLEM_NAME "gymnastics"
    freopen((string(PROBLEM_NAME) + ".in").c_str(), "r", stdin);
    freopen((string(PROBLEM_NAME) + ".out").c_str(), "w", stdout);
    
    int K, N;
    cin >> K >> N;
    vector<vector<int>> sessions(K, vector<int>(N));
    vector<vector<int>> position(K, vector<int>(N + 1));
    for (int k = 0; k < K; ++k) {
        for (int rank = 0; rank < N; ++rank) {
            int cow;
            cin >> cow;
            sessions[k][rank] = cow;
            position[k][cow] = rank;
        }
    }
    int count = 0;
    
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            if (a == b) continue;
    
            bool consistent = true;
    
            for (int k = 0; k < K; ++k) {
                if (position[k][a] > position[k][b]) {
                    consistent = false;
                    break;
                }
            }
    
            if (consistent) count++;
        }
    }
    cout << count << endl;
    return 0;
}
