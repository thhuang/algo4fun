class Solution:

    def sortedSquares(self, nums: List[int]) -> List[int]:
        return sorted([v * v for v in nums])
