class Solution:

    def parseBoolExpr(self, expression: str) -> bool:
        i = 0

        def parse() -> bool:
            nonlocal i

            if expression[i] == "t":
                i += 1
                return True
            if expression[i] == "f":
                i += 1
                return False
            if expression[i] == "!":
                i += 2
                result = parse()
                i += 1
                return not result

            op = expression[i]
            result = True if op == "&" else False

            i += 2

            while expression[i] != ")":
                if expression[i] == ",":
                    i += 1
                elif op == "&":
                    result = parse() and result
                else:  # op == "|"
                    result = parse() or result

            i += 1

            return result

        return parse()
