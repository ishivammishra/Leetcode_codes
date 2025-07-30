class Solution {
public:
    int n, m;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(int r, int c, vector<vector<char>>& board,
             vector<vector<int>>& visit) {
        visit[r][c] = 1;

        for (auto dir : directions) {
            int row = r + dir.first;
            int col = c + dir.second;

            if (row >= 0 and row < n and col >= 0 and col < m and
                board[r][c] == 'X' and !visit[row][col])
                dfs(row, col, board, visit);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        int count = 0;

        vector<vector<int>> visit(n, vector<int>(m, 0));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (board[r][c] == 'X' and !visit[r][c]) {
                    count++;
                    dfs(r, c, board, visit);
                }
            }
        }
        return count;
    }
};