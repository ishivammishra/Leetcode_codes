class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count_map;

        for(int i = 0; i < nums.size(); i++)
        {
            count_map[nums[i]]++;
        }
        vector<int> ans;
        int limit = nums.size()/3;

        for(auto it : count_map)
        {
            int ele = it.first;
            int count = it.second;
            if(count > limit)
                ans.push_back(ele);
        }
        return ans;
    }
};