class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int ans = 0;
        unordered_map<int, int> basket;

        for(int right = 0; right < n; right++)
        {
            basket[fruits[right]]++;
            while(basket.size() > 2)
            {
                basket[fruits[left]]--;
                if(basket[fruits[left]] ==0)
                    basket.erase(fruits[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};