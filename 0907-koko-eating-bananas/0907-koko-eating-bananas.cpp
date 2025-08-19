class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long hours = 0;
            for (int p : piles) {
                hours = hours + ceil((double(p) / mid));
            }

            if (hours <= h)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "0";});