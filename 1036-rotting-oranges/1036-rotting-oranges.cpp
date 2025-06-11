class Solution {
public:
    int n, m;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int fresh = 0;
        int time = 0;
        queue<pair<int, int>> q;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 1)
                    fresh++;
                if (grid[r][c] == 2)
                    q.push({r, c});
            }
        }

        while (fresh > 0 and !q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto current = q.front();
                q.pop();
                int r = current.first;
                int c = current.second;
                for (auto dir : directions) {
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if (row >= 0 and row < n and col >= 0 and col < m and
                        grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0? time : -1;
    }
};