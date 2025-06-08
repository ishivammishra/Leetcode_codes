class Solution {

private:
    void dfs(int curr, int n, vector<int>& ans) {
        if (curr > n)
            return;

        ans.push_back(curr);

        for (int next_digit = 0; next_digit <= 9; next_digit++) {
            int next_num = curr * 10 + next_digit;

            if (next_num <= n)
                dfs(next_num, n, ans);
            else
                break;
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int start = 1; start <= 9; start++) {
            dfs(start, n, ans);
        }
        return ans;
    }
};