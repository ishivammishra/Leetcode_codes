class Solution {
public:
    void solve(int i, int n, int k, vector<int>& op, vector<vector<int>>& res) {
        if (op.size() == k) {
            res.push_back(op);
            return;
        }
        if (i > n) {
            return;
        }

        op.push_back(i);
        solve(i + 1, n, k, op, res);
        op.pop_back();

        solve(i + 1, n, k, op, res);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> op;
        vector<vector<int>> res;
        solve(1, n, k, op, res);
        return res;
    }
};