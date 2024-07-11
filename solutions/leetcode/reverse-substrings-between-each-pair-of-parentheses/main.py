class Solution:

    def reverseParentheses(self, s: str) -> str:
        parentheses = []
        open_indices = []
        chars = []
        for i, c in enumerate(s):
            if c == "(":
                open_indices.append(len(chars))
            elif c == ")":
                parentheses.append((open_indices.pop(), len(chars)))
            else:
                chars.append(c)

        for l, r in parentheses:
            chars[l:r] = chars[l:r][::-1]

        return "".join(chars)
