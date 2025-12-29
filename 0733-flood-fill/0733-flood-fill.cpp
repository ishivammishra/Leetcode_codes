class Solution {
public:
    int n,m;
    vector<pair<int, int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};

    void dfs(int r, int c, vector<vector<int>>& image, int color, int start_col)
    {
        if(!(r >=0 and r < n and c >=0 and c < m and image[r][c] == start_col))
            return;

        image[r][c] = color;

        for(const auto& dir : directions)
        {
            int row = r + dir.first;
            int col = c + dir.second;
            dfs(row, col, image, color, start_col);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();

        int start_col = image[sr][sc];

        if(start_col == color)
            return image;

        dfs(sr, sc, image, color, start_col);
        return image;    
    }
};