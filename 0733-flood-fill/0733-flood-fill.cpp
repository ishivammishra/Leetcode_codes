class Solution {
public:
    void solve(vector<vector<int>>& image, int i, int j, int point, int color) {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() ||
            image[i][j] == color || image[i][j] != point) {
            return;
        }
        image[i][j] = color;
        solve(image, i - 1, j, point, color);
        solve(image, i + 1, j, point, color);
        solve(image, i, j - 1, point, color);
        solve(image, i, j + 1, point, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int point = image[sr][sc];
        solve(image, sr, sc, point, color);
        return image;
    }
};