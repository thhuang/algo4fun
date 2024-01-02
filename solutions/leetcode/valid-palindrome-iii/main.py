class Solution:

    def isValidPalindrome(self, s: str, k: int) -> bool:
        dp = defaultdict(int)
        for d in range(2, len(s) + 1):
            for l in range(0, len(s) - d + 1):
                r = l + d - 1
                if s[l] == s[r]:
                    dp[(l, r)] = dp[(l + 1, r - 1)]
                else:
                    dp[(l, r)] = 1 + min(dp[(l, r - 1)], dp[(l + 1, r)])
        return dp[(0, len(s) - 1)] <= k
