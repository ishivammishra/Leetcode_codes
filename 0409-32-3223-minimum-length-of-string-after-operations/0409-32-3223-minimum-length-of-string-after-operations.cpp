class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> charfre(26, 0);
        int n = s.size();
        int total_length = 0;

        for (int i = 0; i < n; i++) {
            charfre[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (charfre[i] == 0)
                continue;

            if (charfre[i] % 2 == 0) {
                total_length += 2;
            }

            else {
                total_length += 1;
            }
        }
        return total_length;
    }
};