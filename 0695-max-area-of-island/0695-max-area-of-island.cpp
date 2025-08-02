class Solution {
public:
    int n, m;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int dfs(int r, int c, vector<vector<int>>& grid,
            vector<vector<int>>& visit) {
        visit[r][c] = 1;
        int area = 1;

        for (auto dir : directions) {
            int row = r + dir.first;
            int col = c + dir.second;

            if (row >= 0 and row < n and col >= 0 and col < m and
                grid[row][col] == 1 and !visit[row][col])
                area += dfs(row, col, grid, visit);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> visit(n, vector<int>(m, 0));
        int max_area = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 1 and !visit[r][c]) {
                    int area = dfs(r, c, grid, visit);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};