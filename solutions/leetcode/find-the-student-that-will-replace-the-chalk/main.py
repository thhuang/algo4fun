class Solution:

    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        k %= sum(chalk)
        for i, v in enumerate(chalk):
            if k < v:
                return i
            k -= v
        return -1
