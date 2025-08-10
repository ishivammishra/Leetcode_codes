class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        int n = grid.size();
        int m = grid[0].size();

        for (int r1 = x, r2 = x + k - 1; r1 < r2; r1++, r2--) {
            for (int c = y; c <= y + k - 1; c++) {
                swap(grid[r1][c], grid[r2][c]);
            }
        }
        return grid;
    }
};