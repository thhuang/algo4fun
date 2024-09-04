class Solution:

    def isNumber(self, s: str) -> bool:
        integer = "([+-]?\d+)"
        decimal = "([+-]?(\d*\.\d+|\d+\.\d*))"
        integer_or_decimal = f"({integer}|{decimal})"
        exponent = f"([eE]{integer})"
        number = f"({integer_or_decimal}{exponent}?)"
        pattern = f"^{number}$"
        return re.search(pattern, s) is not None
