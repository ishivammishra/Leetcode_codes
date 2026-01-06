class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        long long sum = 0;
        int mini = INT_MAX;
        int cnt = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                sum += abs(matrix[r][c]);

                if (matrix[r][c] < 0)
                    cnt++;

                mini = min(mini, abs(matrix[r][c]));
            }
        }

        if (cnt % 2) {
            sum -= 2 * mini;
        }

        return sum;
    }
};