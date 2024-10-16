class Solution:

    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if m * n != len(original):
            return []
        return [[original[i * n + j] for j in range(n)] for i in range(m)]
