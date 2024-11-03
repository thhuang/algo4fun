class Solution:

    def rotateString(self, s: str, goal: str) -> bool:
        n = len(s)

        if len(goal) != n:
            return False

        def check(k):
            for i in range(n):
                if s[i] != goal[(i + k) % n]:
                    return False
            return True

        for i in range(n):
            if check(i):
                return True

        return False
