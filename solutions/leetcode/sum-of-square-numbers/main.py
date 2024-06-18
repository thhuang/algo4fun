class Solution:

    def judgeSquareSum(self, c: int) -> bool:
        sq = int(sqrt(c) + 1)
        for a in range(sq):
            b = int(sqrt(c - a * a))
            if a * a + b * b == c:
                return True
        return False
