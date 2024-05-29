class Solution:

    def numSteps(self, s: str) -> int:
        result = 0

        v = int(s, 2)
        while v > 1:
            result += 1
            if v % 2 == 1:
                v += 1
            else:
                v //= 2

        return result


class Solution:

    def numSteps(self, s: str) -> int:
        result = 0

        carry = 0
        for c in reversed(s[1:]):
            v = ord(c) - ord("0") + carry
            if v % 2 == 1:
                result += 1
                carry = 1
            result += 1

        return result + carry
