class Solution:

    def partition(self, s: str) -> List[List[str]]:
        n = len(s)

        @cache
        def isPalindrome(l, r):
            print(s[l:r + 1])
            for i in range((r - l + 1) // 2):
                if s[l + i] != s[r - i]:
                    return False
            return True

        result = []
        curr = []

        def search(l):
            if l == n:
                result.append(curr.copy())
                return

            for r in range(l, n):
                if isPalindrome(l, r):
                    curr.append(s[l:r + 1])
                    search(r + 1)
                    curr.pop()

        search(0)

        return result
