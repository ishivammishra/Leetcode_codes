class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        int max_len = 0;
        unordered_map<char, int> mpp;

        while(right < n)
        {
            char c = s[right];

            if(mpp.find(c) != mpp.end() and mpp[c] >= left)
            {
                left = mpp[c] + 1;
            }

            mpp[c] =  right;
            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};