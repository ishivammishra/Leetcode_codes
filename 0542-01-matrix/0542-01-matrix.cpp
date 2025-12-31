class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<int>> dist(n, vector<int>(m, -1));

        queue<pair<int, int>> q;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (mat[r][c] == 0) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

            for (auto dir : directions) {
                int row = r + dir.first;
                int col = c + dir.second;

                if (row >= 0 and row < n and col >= 0 and col < m and
                    dist[row][col] == -1) {
                    dist[row][col] = dist[r][c] + 1;
                    q.push({row, col});
                }
            }
        }
        return dist;
    }
};