class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> op;
        set<vector<int>> temp_ans;

        solve(nums, op, temp_ans);
        vector<vector<int>> ans(temp_ans.begin(), temp_ans.end());
        return ans;
    }

    void solve(vector<int> nums, vector<int> &op, set<vector<int>> &temp_ans)
    {
        if(nums.size() == 0)
        {
            temp_ans.insert(op);
            return;
        }

        vector<int> op1 = op;
        vector<int> op2 = op;

        op2.push_back(nums[0]);
        nums.erase(nums.begin() + 0);

        solve(nums, op1, temp_ans);
        solve(nums, op2, temp_ans); 
    }
};