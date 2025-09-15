class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());

        int count = 0;
        bool can_type = true;

        for (char c : text) 
        {
            if (c == ' ')
            {
                if (can_type)
                    count++;
                can_type = true;
            }
            else if (broken.count(c))
            {
                can_type = false;
            }
        }

        if (can_type)
            count++;

        return count;
    }
};
