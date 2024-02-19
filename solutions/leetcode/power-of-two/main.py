class Solution:

    def __init__(self):
        self.power_of_two = set()
        for i in range(32):
            self.power_of_two.add(1 << i)

    def isPowerOfTwo(self, n: int) -> bool:
        return n in self.power_of_two


class Solution:

    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and n & (n - 1) == 0
