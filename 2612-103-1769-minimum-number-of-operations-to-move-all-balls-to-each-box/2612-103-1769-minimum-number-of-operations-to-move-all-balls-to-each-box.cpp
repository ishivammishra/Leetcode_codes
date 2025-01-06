class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer(boxes.length());
        int n = boxes.length();
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') {
                for (int j = 0; j < n; j++) {
                    answer[j] += abs(j - i);
                }
            }
        }
        return answer;
    }
};