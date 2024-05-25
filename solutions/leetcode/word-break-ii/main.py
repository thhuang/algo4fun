class Solution:

    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        valid = set(wordDict)

        n = len(s)
        dp = [[] for _ in range(n)]
        for r in range(n):
            for l in range(r + 1):
                if l > 0 and len(dp[l - 1]) == 0:
                    continue
                if s[l:r + 1] in valid:
                    dp[r].append(l)

        result = []
        ls = []

        def dfs(r):
            nonlocal result
            nonlocal ls

            if r == -1:
                words = [s[ls[-j]:ls[-j - 1]] for j in range(1, len(ls))]
                words.append(s[ls[0]:])
                result.append(" ".join(words))
                return

            for l in dp[r]:
                ls.append(l)
                dfs(l - 1)
                ls.pop()

        dfs(n - 1)

        return result
