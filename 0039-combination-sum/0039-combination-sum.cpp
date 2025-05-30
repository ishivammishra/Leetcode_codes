class Solution {
public:
    void solve(int i, int target, vector<int>& ds, vector<int>& arr,
               vector<vector<int>> &ans) {

        if (i == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (arr[i] <= target) {
            ds.push_back(arr[i]);
            solve(i, target - arr[i], ds, arr, ans);
            ds.pop_back();
        }
        solve(i + 1, target, ds, arr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, ds, arr, ans);
        return ans;
    }
};