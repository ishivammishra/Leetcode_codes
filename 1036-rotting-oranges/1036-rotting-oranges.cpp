class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1)
                    fresh++;
                if (grid[r][c] == 2)
                    q.push({r, c});
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while (fresh > 0 and !q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for (auto dir : directions) {
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if (row >= 0 and row < m and col >= 0 and col < n and grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};