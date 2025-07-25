class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int left = 0;
        int right = n - 1;

        while (left < n and nums[left] == sorted[left]) {
            left++;
        }
        while (right > left and nums[right] == sorted[right]) {
            right--;
        }

        return (right - left + 1);
    }
};