class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    bool is_peak(int r, int c, vector<vector<int>> &mat, int n, int m)
    {
        for(auto dir : directions)
        {
            int row = r + dir.first;
            int col = c + dir.second;
            if(row >= 0 and row < n and col >= 0 and col < m and mat[row][col] > mat[r][c])
            {
                return false;
            }
            
        }
        return true;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(is_peak(r,c,mat, n, m))
                {
                    return{r,c};
                }
            }
        }
        return {-1,-1};
    }
};