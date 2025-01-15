class Solution:

    def minimizeXor(self, num1: int, num2: int) -> int:
        n = f"{num2:b}".count("1") - f"{num1:b}".count("1")
        return self.add_bits(num1, n) if n >= 0 else self.remove_bits(num1, -n)

    def add_bits(self, v: int, addition: int) -> int:
        for i in range(32):
            mask = 1 << i
            if addition > 0 and v & mask == 0:
                addition -= 1
                v |= mask
        return v

    def remove_bits(self, v: int, removal: int) -> int:
        for i in range(32):
            mask = 1 << i
            if removal > 0 and v & mask != 0:
                removal -= 1
                v ^= mask
        return v
