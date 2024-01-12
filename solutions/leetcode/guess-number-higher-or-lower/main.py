# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:


class Solution:

    def guessNumber(self, n: int) -> int:
        l, r = 1, n + 1  # [l, r)
        while r - l > 1:
            m = (l + r) // 2
            if guess(m) == -1:
                r = m
            else:
                l = m
        return l
