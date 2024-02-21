class Solution:

    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        result = 0

        for i in reversed(range(32)):
            mask = 1 << i
            if left & mask != right & mask:
                break
            result |= left & mask

        return result
