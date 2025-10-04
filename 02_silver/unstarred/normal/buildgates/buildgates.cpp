#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int MAX = 4005; // double the grid size to fit walls and spaces
vector<vector<int>> grid(MAX, vector<int>(MAX, 0));
vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
map<char, int> dir = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); 
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < MAX && ny < MAX) {
                if (!visited[nx][ny] && grid[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    int x = MAX / 2, y = MAX / 2;
    grid[x][y] = 1;

    // Draw the fence, scaled x2 to make walls visible
    for (char c : s) {
        int d = dir[c];
        for (int k = 0; k < 2; ++k) { 
            x += dx[d];
            y += dy[d];
            grid[x][y] = 1; // mark both the edge and intersection as fence
        }
    }

    int chambers = 0;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (!visited[i][j] && grid[i][j] == 0) {
                bfs(i, j);
                chambers++;
            }
        }
    }

    cout << chambers - 1 << "\n"; 
    return 0;
}
