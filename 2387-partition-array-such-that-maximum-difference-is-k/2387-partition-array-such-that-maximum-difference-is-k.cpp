class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1;
        int min = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] - min > k) {
                ans++;
                min = nums[i];
            }
        }
        return ans;
    }
};