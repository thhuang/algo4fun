class Solution:

    class Fraction:

        def __init__(self, numer: int, denom: int) -> None:
            self.numer = numer
            self.denom = denom

        def __add__(self, other):
            numer = self.numer * other.denom + other.numer * self.denom
            if numer == 0:
                return Solution.Fraction(0, 1)

            denom = self.denom * other.denom

            v = gcd(denom, numer)
            return Solution.Fraction(numer // v, denom // v)

        def __str__(self):
            return f"{self.numer}/{self.denom}"

    def fractionAddition(self, expression: str) -> str:

        def getNumber(p):
            v = 0
            while p < len(expression) and expression[p].isdigit():
                v = v * 10 + int(expression[p])
                p += 1
            return p, v

        def getFraction(p, sign):
            p, numer = getNumber(p)
            p, denom = getNumber(p + 1)
            return p, self.Fraction(numer * sign, denom)

        p, sign = (0, 1) if expression[0] != "-" else (1, -1)
        p, result = getFraction(p, sign)

        while p < len(expression):
            p, sign = (p + 1, 1) if expression[p] == "+" else (p + 1, -1)
            p, v = getFraction(p, sign)
            result += v

        return str(result)
