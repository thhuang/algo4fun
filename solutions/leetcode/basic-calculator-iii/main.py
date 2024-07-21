class Solution:

    def calculate(self, s: str) -> int:
        p = 0

        def getNumber() -> int:
            nonlocal p
            result = 0
            while p < len(s) and s[p].isdigit():
                result = result * 10 + int(s[p])
                p += 1
            p -= 1
            return result

        def process() -> int:
            nonlocal p

            total = 0
            last = 0
            sign = 1
            op = "+"

            while p < len(s) and s[p] != ")":
                if s[p] in {"+", "-", "*", "/"}:
                    op = s[p]

                if s[p].isdigit() or s[p] == "(":
                    if s[p] == "(":
                        p += 1
                        v = process()
                    else:
                        v = getNumber()

                    if op == "+":
                        total += sign * last
                        sign = 1
                        last = v
                    elif op == "-":
                        total += sign * last
                        sign = -1
                        last = v
                    elif op == "*":
                        last *= v
                    elif op == "/":
                        last = int(last / v)

                p += 1

            return total + sign * last

        return process()
