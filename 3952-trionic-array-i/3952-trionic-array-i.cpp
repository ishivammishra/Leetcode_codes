class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p = -1;
        int q = -1;

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == nums[i - 1])
                return false;

            if (nums[i] > nums[i - 1] and nums[i] > nums[i + 1]) {
                if (p == -1)
                    p = i;
                else
                    return false;
            }
            if (nums[i] < nums[i - 1] and nums[i] < nums[i + 1]) {
                if (q == -1)
                    q = i;
                else
                    return false;
            }
        }

        return p != -1 and q != -1 and p < q;
    }
};