class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int ans = 0;
        int z_count = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0)
                z_count++;

            while (z_count > 1) {
                if (nums[left] == 0)
                    z_count--;
                left++;
            }

            ans = max(ans, right - left);
        }

        return ans;
    }
};