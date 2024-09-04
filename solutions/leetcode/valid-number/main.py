class Solution:

    def isNumber(self, s: str) -> bool:
        integer = "([+-]?\d+)"
        digits = "((\d+\.\d*)|(\d*\.\d+))"
        decimal = f"([+-]?{digits})"
        exponent = f"([eE]{integer})"
        number = f"(({integer}|{decimal}){exponent}?)"
        pattern = f"^{number}$"
        return re.search(pattern, s) is not None
