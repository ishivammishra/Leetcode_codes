class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int max_len = 0;
        unordered_set<char> hash;

        while(right < n)
        {
            if(hash.find(s[right]) == hash.end())
            {
                hash.insert(s[right]);
                max_len = max(max_len, right - left + 1);
                right++;
            }
            else
            {
                hash.erase(s[left]);
                left++;
            }
        }
        return max_len;
    }
};