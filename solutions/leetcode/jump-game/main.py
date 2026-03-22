class Solution:

    def canJump(self, nums: List[int]) -> bool:
        mx = 0
        for i, v in enumerate(nums):
            if i > mx:
                return False
            mx = max(mx, i + v)
        return True
