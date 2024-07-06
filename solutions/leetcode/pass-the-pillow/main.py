class Solution:

    def passThePillow(self, n: int, time: int) -> int:
        a = time // (n - 1)
        b = time % (n - 1)
        return b + 1 if a % 2 == 0 else n - b
