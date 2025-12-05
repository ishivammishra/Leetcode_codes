class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        for(int num : nums)
        {
            total += num;
        }
        int partitions = 0;
        if(total % 2 == 0)
            partitions = nums.size() - 1;
        else
            partitions = 0;
        
        return partitions;
    }
};