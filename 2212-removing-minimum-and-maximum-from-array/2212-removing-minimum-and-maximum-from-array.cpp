class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_ind = 0, max_ind = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[min_ind])
                min_ind = i;
            if (nums[i] > nums[max_ind])
                max_ind = i;
        }

        if (min_ind > max_ind)
            swap(min_ind, max_ind);

        int removeLeft = max_ind + 1;
        int removeRight = n - min_ind;
        int removeBothEnds = (min_ind + 1) + (n - max_ind);

        return min({removeLeft, removeRight, removeBothEnds});
    }
};