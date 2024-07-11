class Solution:

    def reverseParentheses(self, s: str) -> str:
        parentheses = []
        open_indices = []
        chars = []
        for c in s:
            if c == "(":
                open_indices.append(len(chars))
            elif c == ")":
                parentheses.append((open_indices.pop(), len(chars)))
            else:
                chars.append(c)
        for l, r in parentheses:
            chars[l:r] = chars[l:r][::-1]
        return "".join(chars)


class Solution:

    def reverseParentheses(self, s: str) -> str:
        pairs = {}
        opens = []
        for i, c in enumerate(s):
            if c == "(":
                opens.append(i)
            elif c == ")":
                l, r = opens.pop(), i
                pairs[l], pairs[r] = r, l

        result = []
        i, direction = 0, 1
        for _ in range(len(s)):
            if i in pairs:
                i = pairs[i]
                direction = -direction
            else:
                result.append(s[i])
            i += direction

        return "".join(result)
