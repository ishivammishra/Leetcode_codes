class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[j].find(words[i]) == 0 &&
                    words[j].rfind(words[i]) ==
                        words[j].size() - words[i].size())
                        {
                            count++;
                        }
            }
        }
        return count;
    }
};