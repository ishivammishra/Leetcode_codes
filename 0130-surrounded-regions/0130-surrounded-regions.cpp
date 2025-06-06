class Solution {
public:
    int n, m;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(int r, int c, vector<vector<char>>& board,
             vector<vector<int>>& visit)
    {
        visit[r][c] = 1;

        for (auto dir : directions) {
            int row = r + dir.first;
            int col = c + dir.second;

            if (row >= 0 and row < m and col >= 0 and col < n and
                board[row][col] == 'O' and !visit[row][col]) {
                    dfs(row, col, board, visit);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<int>> visit(m, vector<int>(n, 0));

        // checking first column and last column
        for (int r = 0; r < m; r++) {
            // first col
            if (board[r][0] == 'O' and !visit[r][0])
                dfs(r, 0, board, visit);

            // last col
            if (board[r][n - 1] == 'O' and !visit[r][n - 1])
                dfs(r, n - 1, board, visit);
        }

        // checking first row and last row
        for (int c = 0; c < n; c++) {
            if (board[0][c] == 'O' and !visit[0][c])
                dfs(0, c, board, visit);

            if (board[m - 1][c] == 'O' and !visit[m - 1][c])
                dfs(m - 1, c, board, visit);
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O' and !visit[r][c])
                    board[r][c] = 'X';
            }
        }
    }
};