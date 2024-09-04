class Solution:

    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        start, length = 0, 0

        def updateLongestPalindrome(l: int, r: int):
            nonlocal start
            nonlocal length
            while 0 <= l and r < n and s[l] == s[r]:
                l -= 1
                r += 1
            l += 1
            d = r - l
            if length < d:
                start, length = l, d

        for i in range(n):
            updateLongestPalindrome(i, i)
            if i > 0:
                updateLongestPalindrome(i - 1, i)

        return s[start:start + length]
