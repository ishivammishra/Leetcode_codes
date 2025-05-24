class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maximum = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            maximum = max(nums[left] + nums[right], maximum);
            left++;
            right--;
        }

        return maximum;
    }
};