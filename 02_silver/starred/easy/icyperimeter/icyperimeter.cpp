#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
using namespace std;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int n;

struct blob {
    int p, a;
};

blob dfs(int x, int y, vector<vector<bool>> &visited, const vector<vector<char>> &grid) {
    visited[x][y] = true;
    blob b = {0, 1};

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] != '#') {
            b.p++;
        } else if (!visited[nx][ny]) {
            blob sub = dfs(nx, ny, visited, grid);
            b.a += sub.a;
            b.p += sub.p;
        }
    }

    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<blob> ans;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (!visited[x][y] && grid[x][y] == '#') {
                ans.push_back(dfs(x, y, visited, grid));
            }
        }
    }

    sort(ans.begin(), ans.end(), [](const blob &A, const blob &B) {
        if (A.a != B.a) return A.a > B.a;
        return A.p < B.p;
    });

    cout << ans[0].a << " " << ans[0].p << "\n";
}
