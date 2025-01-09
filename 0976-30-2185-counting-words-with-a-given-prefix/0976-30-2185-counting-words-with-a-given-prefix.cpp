class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int count = 0;
        int len = pref.size();

        for (int i = 0; i < n; i++) {
            if (words[i].size() >= len)
            {
                if(words[i].substr(0,len) == pref)
                {
                    count++;
                }
            }
        }
        return count;
    }
};