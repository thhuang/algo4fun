class Solution:

    def combinationSum3(self, k: int, n: int) -> List[List[int]]:

        result = []
        curr = []

        def dfs(i):
            nonlocal k
            nonlocal n

            if k == 0:
                if n == 0:
                    result.append(curr.copy())
                return
            if n < 0:
                return
            if i == 10:
                return

            dfs(i + 1)

            curr.append(i)
            k -= 1
            n -= i
            dfs(i + 1)
            n += i
            k += 1
            curr.pop()

        dfs(1)

        return result
