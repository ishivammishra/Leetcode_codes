class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int left  = nums[0];

        for(int i = 1 ; i < n-1; i++)
        {
            if(nums[i] == nums[i+1]) continue;

            if(nums[i] > left and nums[i] > nums[i+1] or nums[i] < left and nums[i] < nums[i+1])
                count++;
            
            left = nums[i];
        }
        return count;
    }
};