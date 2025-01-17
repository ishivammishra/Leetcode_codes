class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int Sum = 0;
        for (int num : derived) {
            Sum ^= num;
        }
        return Sum == 0;
    }
};