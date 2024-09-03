class Solution:

    def validPalindrome(self, s: str) -> bool:

        def findDiff(s: str, skip: int) -> bool:
            n = len(s)
            l, r = 0, n - 1
            while l < r:
                if l == skip:
                    l += 1
                elif r == skip:
                    r -= 1
                elif s[l] != s[r]:
                    return l, r
                else:
                    l += 1
                    r -= 1
            return None, None

        i, j = findDiff(s, -1)

        if i is None:
            return True

        return findDiff(s, i)[0] is None or findDiff(s, j)[0] is None
