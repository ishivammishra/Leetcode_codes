class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int count = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (board[r][c] == 'X') {
                    if (r > 0 and board[r - 1][c] == 'X')
                        continue;
                    if (c > 0 and board[r][c - 1] == 'X')
                        continue;
                    count++;
                }
            }
        }
        return count;
    }
};