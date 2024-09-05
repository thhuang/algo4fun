class Solution:

    def countSubstrings(self, s: str) -> int:
        n = len(s)

        def check(l, r):
            while 0 <= l <= r < n and s[l] == s[r]:
                l, r = l - 1, r + 1
            return l + 1, r

        result = 0

        for i in range(n):
            l, r = check(i, i)
            result += (r - l + 1) // 2

        for i in range(n - 1):
            l, r = check(i, i + 1)
            if l < r:
                result += (r - l) // 2

        return result


class Solution:

    def countSubstrings(self, s: str) -> int:
        n = len(s)
        result = 0

        def search(l, r):
            nonlocal result
            while 0 <= l and r < n and s[l] == s[r]:
                l -= 1
                r += 1
            result += (r - l) // 2

        for i in range(n):
            search(i, i)
            if i > 0:
                search(i - 1, i)

        return result
