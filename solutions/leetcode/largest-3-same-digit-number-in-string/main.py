class Solution:

    def largestGoodInteger(self, num: str) -> str:
        result = ""
        for r in range(3, len(num) + 1):
            l = r - 3
            if num[l] == num[l + 1] == num[l + 2] and (result == ""
                                                       or num[l] > result[0]):
                result = num[l:r]
        return result
