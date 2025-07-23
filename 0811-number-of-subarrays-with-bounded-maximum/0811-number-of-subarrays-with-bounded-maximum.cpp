class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int ans = 0;
        int valid = -1;
        int invalid = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] >= left and nums[i] <= right)
                valid = i;
            if(nums[i] > right)
                invalid = i;

            ans = ans + max(0, valid - invalid);
        }
        return ans;
    }
};