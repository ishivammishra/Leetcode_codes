class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans = "";
        for(int i = 2; i < n; i++)
        {
            if(num[i] == num[i-1] and num[i-1] == num[i-2])
            {
                string triple = num.substr(i-2,3);
                ans = max(ans, triple);
            }
        }
        return ans;
    }
};