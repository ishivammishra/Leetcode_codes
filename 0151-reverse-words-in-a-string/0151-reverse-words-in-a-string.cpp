class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        vector<string> word;
        int left = 0;

        while (left < n) {
            while (left < n and s[left] == ' ')
                left++;
            if (left >= n)
                break;

            int right = left;

            while (right < n and s[right] != ' ')
                right++;

            word.push_back(s.substr(left, right - left));
            left = right;
        }

        string ans = "";
       for (int i = word.size() - 1; i >= 0; i--) {
            ans += word[i];
            if (i != 0)
                ans += " ";
        }
        return ans;
    }
};