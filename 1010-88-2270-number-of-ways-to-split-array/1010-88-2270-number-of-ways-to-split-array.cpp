class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long leftsum = 0;
        long long rightsum = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            rightsum += nums[i];
        }

        int split = 0;

        for(int i = 0; i< nums.size()-1; i++)
        {
            leftsum += nums[i];
            rightsum -= nums[i];

            if(leftsum >= rightsum)
            {
                split++;
            }
        }

        return split;
    }
};