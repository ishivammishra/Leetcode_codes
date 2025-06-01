class Solution {
public:
    void solve(string digits, string op, int ind, vector<string>& ans,
               vector<string>& buttons) {

        if (ind >= digits.length()) {
            ans.push_back(op);
            return;
        }

        int num = digits[ind] - '0';
        string str = buttons[num];

        for (int i = 0; i < str.length(); i++) {
            op.push_back(str[i]);
            solve(digits, op, ind + 1, ans, buttons);
            op.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        string op;
        int ind = 0;
        vector<string> buttons = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, op, ind, ans, buttons);
        return ans;
    }
};