class Solution:

    def calculate(self, s: str) -> int:
        p = 0

        def parseNumber() -> int:
            nonlocal p
            result = 0
            while p < len(s) and s[p].isdigit():
                result = result * 10 + int(s[p])
                p += 1
            p -= 1
            return result

        def parseExpression() -> int:
            nonlocal p

            result = 0
            sign = 1

            while p < len(s) and s[p] != ")":
                if s[p] == "+":
                    sign = 1
                elif s[p] == "-":
                    sign = -1
                elif s[p] == "(":
                    p += 1
                    result += parseExpression() * sign
                elif s[p] == ")":
                    return result
                elif s[p].isdigit():
                    result += parseNumber() * sign
                p += 1

            return result

        return parseExpression()
