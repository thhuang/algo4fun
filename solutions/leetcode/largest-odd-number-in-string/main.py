class Solution:

    def largestOddNumber(self, num: str) -> str:
        i = len(num) - 1
        while i >= 0 and int(num[i]) % 2 == 0:
            i -= 1
        if i == -1:
            return ""
        return num[:i + 1]
