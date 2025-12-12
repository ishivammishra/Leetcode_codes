class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mapp;

        for(auto &s : arr)
        {
            mapp[s]++;
        }

        for(auto &s : arr)
        {
            if(mapp[s] == 1)
            {
                k--;
                if(k == 0) return s;
            }
        }

        return "";
    }
};