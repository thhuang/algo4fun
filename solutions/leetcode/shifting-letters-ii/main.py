class Solution:

    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        dx = [0] * (len(s) + 1)
        for l, r, d in shifts:
            v = 1 if d == 1 else -1
            dx[l] += v
            dx[r + 1] -= v

        x = [dx[0]]
        for i in range(1, len(s) + 1):
            x.append(x[-1] + dx[i])

        shifted = [self.shift(s[i], x[i]) for i in range(len(s))]
        return "".join(shifted)

    def shift(self, c: str, dist: int) -> str:
        i = ord(c) - ord("a")
        j = (i + dist) % 26
        return chr(ord("a") + j)
