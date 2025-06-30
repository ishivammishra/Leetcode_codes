class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_len = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {

            while (nums[j] - nums[i] > 1) {
                i++;
            }

            if (nums[j] - nums[i] == 1)
                max_len = max(max_len, j - i + 1);
        }
        return max_len;
    }
};