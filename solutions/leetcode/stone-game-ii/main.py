class Solution:

    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        suffix_sum = [0] * (n + 1)
        for i in reversed(range(n)):
            suffix_sum[i] = suffix_sum[i + 1] + piles[i]

        @cache
        def dfs(l: int, m: int) -> int:
            result = 0
            v = 0
            for x in range(1, m * 2 + 1):
                r = l + x
                if r > n:
                    break
                v += piles[r - 1]
                result = max(result, v + suffix_sum[r] - dfs(r, max(m, x)))

            return result

        return dfs(0, 1)
