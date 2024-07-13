class Solution:

    def maximumGain(self, s: str, x: int, y: int) -> int:
        order = sorted([(x, "ab"), (y, "ba")])[::-1]
        s, a = self.removeSubstrings(s, *order[0])
        _, b = self.removeSubstrings(s, *order[1])
        return a + b

    def removeSubstrings(self, s, v, t):
        result = 0
        chars = []

        for c in s:
            chars.append(c)
            if len(chars) >= 2 and chars[-2] == t[0] and chars[-1] == t[1]:
                chars.pop()
                chars.pop()
                result += v

        return "".join(chars), result
