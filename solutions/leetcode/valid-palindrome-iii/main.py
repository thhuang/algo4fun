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


class Solution:

    def isValidPalindrome(self, s: str, k: int) -> bool:
        n = len(s)
        dp1 = [0 for _ in range(n)]
        dp2 = [0 for _ in range(n)]
        for d in range(2, n + 1):
            dp0 = [0 for _ in range(n)]
            for l in range(0, n - (d - 1)):
                r = l + d - 1
                if s[l] == s[r]:
                    dp0[l] = dp2[l + 1]
                else:
                    dp0[l] = 1 + min(dp1[l], dp1[l + 1])
            dp1, dp2 = dp0, dp1
        return dp0[0] <= k
