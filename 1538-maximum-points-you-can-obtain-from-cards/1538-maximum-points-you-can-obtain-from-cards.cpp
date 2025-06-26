class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0;
        int right = 0;
        int maxi = 0;

        for (int i = 0; i < k; i++) {
            left += cardPoints[i];
        }
        maxi = left;

        int right_ind = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            left = left - cardPoints[i];
            right += cardPoints[right_ind];
            right_ind--;

            maxi = max(maxi, left + right);
        }
        return maxi;
    }
};