class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        left = 0
        right = n-1
        max_water = 0
        
        while left <= right:
            w = right - left
            h = min(height[left], height[right])
            actual_water = w * h
            max_water = max(max_water, actual_water)

            if height[left] < height[right]:
                left = left + 1
            else:
                right = right - 1
        return max_water
        