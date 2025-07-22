class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int max_sum = 0;

        unordered_set<int> st;

        for (int right = 0; right < n; right++) {
            while (st.count(nums[right])) {
                st.erase(nums[left]);
                sum = sum - nums[left];
                left++;
            }

            st.insert(nums[right]);
            sum = sum + nums[right];
            max_sum = max(max_sum, sum);
        }

        return max_sum;
    }
};