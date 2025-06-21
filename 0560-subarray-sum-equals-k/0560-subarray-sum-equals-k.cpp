class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int sum = 0, ans = 0;
        mpp[0] = 1;

        for(int it : nums)
        {
            sum += it;
            int find = sum-k;
            if(mpp.find(find) != mpp.end())
            {
                ans += mpp[find];
            }
            mpp[sum]++;
        }
        return ans;
    }
};