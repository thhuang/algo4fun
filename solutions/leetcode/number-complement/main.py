class Solution:

    def findComplement(self, num: int) -> int:
        binary = bin(num)[2:]
        flipped = "".join('0' if b == '1' else '1' for b in binary)
        return int(flipped, 2)
