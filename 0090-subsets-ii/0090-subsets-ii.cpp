class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> op;
        set<vector<int>> temp;

        solve(nums, op, temp);
        vector<vector<int>> ans(temp.begin(), temp.end());
        return ans;
    };

    void solve(vector<int> nums, vector<int> &op, set<vector<int>> &temp)
    {
        if(nums.size() == 0)
        {
            temp.insert(op);
            return;
        }

        vector<int> op1 = op;
        vector<int> op2 = op;

        op2.push_back(nums[0]);
        nums.erase(nums.begin() + 0);

        solve(nums, op1, temp);
        solve(nums, op2, temp);
    }
};