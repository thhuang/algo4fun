class Solution:

    def reverse(self, s: List[str], l: int, r: int) -> None:
        for i in range((r - l + 1) // 2):
            s[l + i], s[r - i] = s[r - i], s[l + i]

    def reverseWords(self, s: str) -> str:
        t = []
        for c in s.strip():
            if c == ' ' and len(t) > 0 and t[-1] == ' ':
                continue
            t.append(c)

        self.reverse(t, 0, len(t) - 1)

        l = 0
        while l < len(t):
            r = l
            while r < len(t) and t[r] != ' ':
                r += 1
            self.reverse(t, l, r - 1)
            l = r + 1

        return "".join(t)
