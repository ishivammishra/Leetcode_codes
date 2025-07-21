class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int maxi = 1;
        int con = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1])
                con++;
            else
                con = 1;

            maxi = max(maxi, con);
        }
        return maxi;
    }
};