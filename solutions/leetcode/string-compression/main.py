class Solution:

    def compress(self, chars: List[str]) -> int:
        p = 0

        l = 0
        while l < len(chars):
            r = l + 1
            while r < len(chars) and chars[r] == chars[l]:
                r += 1
            v = r - l

            chars[p] = chars[l]
            p += 1

            if v > 1:
                for c in str(v):
                    chars[p] = c
                    p += 1

            l = r

        return p
