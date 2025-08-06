class Solution {
public:
    bool vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int left = 0, right = 0;
        int count = 0;
        int maxi = 0;

        while (right < s.length()) {
            if (vowel(s[right]))
                count++;

            if (right - left + 1 > k) {
                if (vowel(s[left]))
                    count--;
                left++;
            }

            if (right - left + 1 == k)
                maxi = max(maxi, count);

            right++;
        }
        return maxi;
    }
};