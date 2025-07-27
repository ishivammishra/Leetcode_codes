class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true;
        bool dec = true;
        int n = nums.size();

        for(int i = 1; i< n; i++)
        {
            if(nums[i] > nums[i-1]) 
                dec = false;
            if(nums[i] < nums[i-1])
                inc = false;
        }

        return inc or dec;
    }
};