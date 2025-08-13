class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }

        vector<int> ans;
        int limit = n / 3;

        for (auto it : map) {
            int element = it.first;
            int count = it.second;

            if (count > limit) {
                ans.push_back(element);
            }
        }
        return ans;
    }
};