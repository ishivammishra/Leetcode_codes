class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mapp;
        int maxi = 0;
        int count = 0;

        for(int n : nums)
        {
            mapp[n]++;
            maxi = max(maxi, mapp[n]);
        }

        for(auto& it : mapp)
        {
            if(it.second == maxi)
            {
                count = count + it.second;
            }
        }

        return count;
    }
};