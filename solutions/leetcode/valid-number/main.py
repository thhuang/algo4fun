class Solution:

    def isNumber(self, s: str) -> bool:
        integer = f"([+-]?\d+)"
        decimal = f"([+-]?((\d+\.\d*)|(\d*\.\d+)))"
        exponent = f"([eE]{integer})"
        number = f"(({integer}|{decimal}){exponent}?)"
        pattern = f"^{number}$"
        return re.search(pattern, s) is not None
