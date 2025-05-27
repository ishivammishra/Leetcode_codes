class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> op;
        vector<vector<int>> ans;
        solve(1, n, k, op, ans);
        return ans;
    }

    void solve(int i, int n, int k, vector<int>& op, vector<vector<int>>& ans) {

        if (op.size() == k) {
            ans.push_back(op);
            return;
        }
        if (i > n)
            return;

        op.push_back(i);
        solve(i + 1, n, k, op, ans);
        op.pop_back();
        solve(i + 1, n, k, op, ans);
    }
};