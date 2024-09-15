class Solution:

    def findTheLongestSubstring(self, s: str) -> int:
        mp = {"a": 0, "e": 1, "i": 2, "o": 3, "u": 4}
        n = len(s)

        right_most = {0: n}
        suffix_xor = {n: 0}
        result = 0

        for i in reversed(range(n)):
            v = 0
            if s[i] in mp:
                v ^= 1 << mp[s[i]]

            xor = suffix_xor[i + 1] ^ v
            suffix_xor[i] = xor

            if xor in right_most:
                result = max(result, right_most[xor] - i)
            else:
                right_most[xor] = i

        return result
