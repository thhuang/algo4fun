class Solution:

    def isValid(self, s: str) -> bool:
        mp = {
            ")": "(",
            "]": "[",
            "}": "{",
        }

        seen = []

        for c in s:
            if c not in mp:
                seen.append(c)
            elif len(seen) == 0 or seen[-1] != mp[c]:
                return False
            else:
                seen.pop()

        return len(seen) == 0
