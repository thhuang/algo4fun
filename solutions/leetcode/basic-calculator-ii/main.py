class Solution:

    def calculate(self, s: str) -> int:
        total = 0
        last = 0
        sign = 1
        op = "+"

        p = 0
        while p < len(s):
            if s[p] in {"+", "-", "*", "/"}:
                op = s[p]

            elif s[p].isdigit():
                v = 0
                while p < len(s) and s[p].isdigit():
                    v = v * 10 + int(s[p])
                    p += 1
                p -= 1

                if op == "+":
                    total += last * sign
                    last = v
                    sign = 1
                elif op == "-":
                    total += last * sign
                    last = v
                    sign = -1
                elif op == "*":
                    last *= v
                elif op == "/":
                    last //= v

            p += 1

        return total + last * sign
