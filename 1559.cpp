class Solution {
private:
    bool dfs(int r, int c, int pr, int pc, vector<vector<char>>& grid, vector<vector<bool>>& visited, char val) {
        visited[r][c] = true;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == val) {
                if (nr == pr && nc == pc) continue;
                if (visited[nr][nc]) return true;
                if (dfs(nr, nc, r, c, grid, visited, val)) return true;
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid, visited, grid[i][j])) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};