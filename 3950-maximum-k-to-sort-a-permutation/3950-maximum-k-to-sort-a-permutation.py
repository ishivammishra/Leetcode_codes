class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        n = len(nums)
        ans = -1
        for i in range(n):
            if nums[i] != i:
                ans = i
                break
        if ans == -1:
            return 0
        for i in range(n):
            if nums[i] != i:
                ans = ans & i
        
        return ans