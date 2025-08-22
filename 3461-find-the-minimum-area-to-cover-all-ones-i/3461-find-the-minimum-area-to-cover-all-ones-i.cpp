class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int min_row = n, max_row = -1, min_col = m, max_col = -1;

        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(grid[r][c] == 1)
                {
                    if(r < min_row)
                        min_row = r;
                    if(r > max_row)
                        max_row = r;
                    if(c < min_col)
                        min_col = c;
                    if(c > max_col)
                        max_col = c;
                }
            }
        }
        if(max_row == -1) return 0;
        int length = max_row - min_row + 1;
        int width = max_col - min_col + 1;

        return length * width;
    }
};