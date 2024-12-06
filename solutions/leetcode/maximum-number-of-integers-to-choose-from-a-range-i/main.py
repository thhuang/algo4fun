class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned = set(banned)
        result = 0
        for i in range(1, n + 1):
            if i in banned:
                continue
            if i > maxSum:
                break
            maxSum -= i
            result += 1
        return result
