class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> row, col;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == 0) {
                    row.insert(r);
                    col.insert(c);
                }
            }
        }

        for (auto r : row) {
            for (int i = 0; i < n; i++)
                matrix[r][i] = 0;
        }

        for (auto c : col) {
            for (int i = 0; i < m; i++)
                matrix[i][c] = 0;
        }
    }
};