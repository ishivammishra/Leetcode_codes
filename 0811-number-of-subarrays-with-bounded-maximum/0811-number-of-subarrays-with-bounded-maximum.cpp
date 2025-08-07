class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int start = 0;
        
        int count= 0;
        int ans = 0;

        for(int end = 0; end < n; end ++ )
        {
            if(nums[end] >= left and nums[end] <= right)
            {
                count = end - start + 1;
                ans =  ans + count;
            }
            else if(nums[end] < left)
            {
                ans = ans + count;
            }
            else
            {
                start = end + 1;
                count = 0;
            }
        }
        return ans;
    }
};