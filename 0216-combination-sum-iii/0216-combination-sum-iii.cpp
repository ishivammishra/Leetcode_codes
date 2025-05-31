class Solution {

public:
    void solve(int ind, int target, vector<int>& ds, int k,
               vector<vector<int>>& ans) {
        if (target == 0 and ds.size() == k) {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i <= 9; i++) {
            if (i > target)
                break;
            ds.push_back(i);
            solve(i + 1, target - i, ds, k, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1, n, ds, k, ans);
        return ans;
    }
};