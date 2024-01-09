# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, row: int, col: int) -> int:
#    def dimensions(self) -> list[]:


class Solution:

    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        rows, cols = binaryMatrix.dimensions()

        result = cols
        for row in range(rows):
            l, r = -1, cols  # (l, r]
            while r - l > 1:
                m = (l + r) // 2
                if binaryMatrix.get(row, m) == 1:
                    r = m
                else:
                    l = m
            result = min(result, r)

        return result if result < cols else -1
