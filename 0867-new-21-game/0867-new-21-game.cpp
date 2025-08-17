class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double window_sum = 1.0, result = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = window_sum / maxPts;

            if (i < k) {
                window_sum += dp[i];  
            } else {
                result += dp[i];
            }

            if (i - maxPts >= 0) {
                window_sum -= dp[i - maxPts]; 
            }
        }
        return result;
    }
};
