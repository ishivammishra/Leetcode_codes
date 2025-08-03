class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int ans = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int curr = weight[i];
            maxi = max(maxi, curr);
            if (curr < maxi) {
                ans++;
                maxi = 0;
            }
        }
        return ans;
    }
};