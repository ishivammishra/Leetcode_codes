class Solution {
public:
    int n, m;
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void dfs(int r, int c, vector<vector<int>>& image, int color,
             int startColor) {
        if (!(r >= 0 && r < n && c >= 0 && c < m && image[r][c] == startColor))
            return;

        image[r][c] = color;

        for (const auto& dir : directions) {
            int row = r + dir.first;
            int col = c + dir.second;
            dfs(row, col, image, color, startColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        n = image.size();
        m = image[0].size();
        int startColor = image[sr][sc];

        if (startColor == color)
            return image;

        dfs(sr, sc, image, color, startColor);
        return image;
    }
};
