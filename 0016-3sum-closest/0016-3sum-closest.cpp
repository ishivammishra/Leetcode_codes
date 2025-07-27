class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long close = INT_MAX;

        for(int i = 0; i<n ;i++)
        {
            int left = i+1;
            int right = n-1;
            while(left < right)
            {
                long long sum = nums[i] + nums[left] + nums[right];

                if(sum == target)
                return sum;

                if(abs(sum - target) < abs(close - target))
                    close = sum;
                
                if(sum > target)
                    right--;
                else
                    left++;

            }
        }

        return close;
    }
};