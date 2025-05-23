class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int left_max = 0, right_max = 0;
        int trapped_wtr = 0;

        while(left <= right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] >= left_max)
                    left_max = height[left];
                else
                    trapped_wtr += left_max - height[left];
                
                left++;
            }
            else
            {
                if(height[right] >= right_max)
                    right_max = height[right];
                else
                    trapped_wtr += right_max - height[right]; 
                
                right--;
            }
        }
        return trapped_wtr;
    }
};