class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            for (auto dir : directions) {
                int row = r + dir.first;
                int col = c + dir.second;

                if (row >= 0 and row < m and col >= 0 and col < n and dist[row][col] == -1) {
                    dist[row][col] = dist[r][c] + 1;
                    q.push({row, col});
                }
            }
        }
        return dist;
    }
};