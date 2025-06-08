class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int peri = 0;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 1) {
                    peri += 4;

                    // checking above
                    if (r > 0 and grid[r - 1][c] == 1)
                        peri -= 2;

                    // checking left
                    if (c > 0 and grid[r][c - 1] == 1)
                        peri -= 2;
                }
            }
        }
        return peri;
    }
};