class Solution {
public:
    int n, m;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(int r, int c, vector<vector<int>>& grid,
             vector<vector<int>>& visit) {
        visit[r][c] = 1;
        for (auto dir : directions) {
            int row = r + dir.first;
            int col = c + dir.second;

            if (row >= 0 and row < n and col >= 0 and col < m and grid[row][col] == 1 and !visit[row][col])
            {
                dfs(row, col, grid, visit);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> visit(n, vector<int>(m, 0));

        // first col and last col
        for (int r = 0; r < n; r++) {
            if (grid[r][0] == 1 and !visit[r][0])
                dfs(r, 0, grid, visit);
            if (grid[r][m - 1] == 1 and !visit[r][m - 1])
                dfs(r, m - 1, grid, visit);
        }

        int count = 0;
        // first row and last row
        for (int c = 0; c < m; c++) {
            if (grid[0][c] == 1 and !visit[0][c])
                dfs(0, c, grid, visit);
            if (grid[n - 1][c] == 1 and !visit[n - 1][c])
                dfs(n - 1, c, grid, visit);
        }

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 1 and !visit[r][c]) {
                    count++;
                }
            }
        }
        return count;
    }
};