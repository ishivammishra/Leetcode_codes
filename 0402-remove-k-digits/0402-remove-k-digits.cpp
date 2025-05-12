class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if (k == 0) {
            return num;
        }

        if (n <= k) {
            return "0";
        }

        string ans = "";
        stack<char> s;
        s.push(num[0]);

        for (int i = 1; i < n; i++) {
            while (!s.empty() and k > 0 and num[i] < s.top()) {
                s.pop();
                k--;
            }

            s.push(num[i]);

            if (s.size() == 1 and num[i] == '0') {
                s.pop();
            }
        }
            while (k and !s.empty()) {
                s.pop();
                k--;
            }

            while (!s.empty()) {
                ans.push_back(s.top());
                s.pop();
            }

            reverse(ans.begin(), ans.end());

            if (ans.length() == 0)
                return "0";

            return ans;
        }
    
};