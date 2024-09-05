class Solution:

    def addStrings(self, num1: str, num2: str) -> str:
        i, j = len(num1) - 1, len(num2) - 1
        carry = 0
        rresult = []
        while carry > 0 or i >= 0 or j >= 0:
            if i >= 0:
                carry += int(num1[i])
                i -= 1
            if j >= 0:
                carry += int(num2[j])
                j -= 1
            rresult.append(str(carry % 10))
            carry //= 10
        return "".join(rresult[::-1])
