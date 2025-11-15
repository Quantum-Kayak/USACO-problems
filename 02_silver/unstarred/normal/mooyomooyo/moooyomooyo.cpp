#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int n, k;
int floodfill(int sx, int sy, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
    int rows = n;
    int cols = 10; 

    queue<pair<int, int>> q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    int color = grid[sx][sy];
    vis[sx][sy] = true;
    q.push({sx, sy});

    int cnt = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        cnt++;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                !vis[nx][ny] && grid[nx][ny] == color) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);

    cin >> n >> k;
    vector<vector<int>> grid(n, vector<int>(10));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++) {
            grid[i][j] = s[j] - '0';
        }
    }

    while (true) {
        bool any_removed = false;

        vector<vector<bool>> vis(n, vector<bool>(10, false));
        vector<vector<bool>> to_clear(n, vector<bool>(10, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (grid[i][j] != 0 && !vis[i][j]) {
                    int color = grid[i][j];
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;

                    vector<pair<int, int>> cells;
                    cells.push_back({i, j});

                    int dx[4] = {1, 0, -1, 0};
                    int dy[4] = {0, -1, 0, 1};

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < 10 &&
                                !vis[nx][ny] && grid[nx][ny] == color) {
                                vis[nx][ny] = true;
                                q.push({nx, ny});
                                cells.push_back({nx, ny});
                            }
                        }
                    }

                    if ((int)cells.size() >= k) {
                        any_removed = true;
                        for (auto &p : cells) {
                            to_clear[p.first][p.second] = true;
                        }
                    }
                }
            }
        }

        if (!any_removed) break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (to_clear[i][j]) {
                    grid[i][j] = 0;
                }
            }
        }

        for (int col = 0; col < 10; col++) {
            int write_row = n - 1; 
            for (int row = n - 1; row >= 0; row--) {
                if (grid[row][col] != 0) {
                    grid[write_row][col] = grid[row][col];
                    if (write_row != row) {
                        grid[row][col] = 0;
                    }
                    write_row--;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}
