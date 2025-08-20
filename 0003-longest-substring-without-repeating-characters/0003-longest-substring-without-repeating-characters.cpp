class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int max_len = 0;
        unordered_map<char, int> mapp;

        while(right < n)
        {
            char c = s[right];
            if(mapp.find(c) != mapp.end() and mapp[c] >= left)
            {
                left = mapp[c] + 1;

            }
            mapp[c] = right;

            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};