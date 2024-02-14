class Solution:

    def isAdditiveNumber(self, num: str) -> bool:
        curr = []

        def dfs(l):
            if l == len(num):
                if len(curr) >= 3:
                    return True
                return False

            for r in range(l, len(num)):
                if r != l and num[l] == "0":
                    break

                v = int(num[l:r + 1])

                if len(curr) >= 2 and curr[-2] + curr[-1] != v:
                    continue

                curr.append(v)
                if dfs(r + 1):
                    return True
                curr.pop()

            return False

        return dfs(0)
