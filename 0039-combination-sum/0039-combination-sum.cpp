class Solution {
public:
    void solve(int i, int target, vector<int>& ds, vector<int>& candi,
               vector<vector<int>>& ans) {

        if (i == candi.size()) {
            if (target == 0)
                ans.push_back(ds);
            return;
        }

        if (candi[i] <= target) {
            ds.push_back(candi[i]);
            solve(i, target - candi[i], ds, candi, ans);
            ds.pop_back();
        }
        solve(i + 1, target, ds, candi, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, ds, candidates, ans);

        return ans;
    }
};