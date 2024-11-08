class Solution:

    def largestCombination(self, candidates: List[int]) -> int:
        result = 0
        for i in range(32):
            mask = 1 << i
            cnt = sum([mask & v != 0 for v in candidates])
            result = max(result, cnt)
        return result
