class Solution {
public:
    bool vowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        else
            return false;
    }
    int maxVowels(string s, int k) {
        int count = 0;
        int maxi = 0;

        for (int i = 0; i < s.length(); i++) {
            if (vowel(s[i]))
                count++;

            if (i >= k and vowel(s[i - k]))
                count--;

            if (count > maxi)
                maxi = count;
        }
        return maxi;
    }
};