class Solution {
public:
    int n, m;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(int r, int c, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {
        visited[r][c] = '1';

        for (auto dir : directions) {
            int row = r + dir.first;
            int col = c + dir.second;

            if (row >= 0 and row < n and col >= 0 and col < m and
                grid[row][col] == '1' and !visited[row][col])
                dfs(row, col, grid, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == '1' and !visited[r][c]) {
                    count++;
                    dfs(r, c, grid, visited);
                }
            }
        }
        return count;
    }
};