class Solution:

    def sumSubarrayMins(self, arr: List[int]) -> int:
        mod = int(1e9 + 7)
        n = len(arr)

        asc = []

        r = [None] * n
        for i in range(n):
            while len(asc) > 0 and arr[asc[-1]] > arr[i]:
                r[asc[-1]] = i - 1
                asc.pop()
            asc.append(i)
        while len(asc) > 0:
            r[asc[-1]] = n - 1
            asc.pop()

        l = [None] * n
        for i in range(n)[::-1]:
            while len(asc) > 0 and arr[asc[-1]] >= arr[i]:
                l[asc[-1]] = i + 1
                asc.pop()
            asc.append(i)
        while len(asc) > 0:
            l[asc[-1]] = 0
            asc.pop()

        result = 0
        for i, v in enumerate(arr):
            result = (result + v * (i - l[i] + 1) * (r[i] - i + 1)) % mod

        return result


class Solution:

    def sumSubarrayMins(self, arr: List[int]) -> int:
        arr = [0] + arr
        asc = [0]
        dp = [0] * len(arr)

        for r, v in enumerate(arr):
            while len(asc) > 0 and arr[asc[-1]] > v:
                asc.pop()
            l = asc[-1]
            dp[r] = dp[l] + v * (r - l)
            asc.append(r)

        return sum(dp) % int(1e9 + 7)
