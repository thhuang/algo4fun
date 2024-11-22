class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        result = 0
        freq = defaultdict(int)
        for row in matrix:
            flip = row[0] == 0
            seq = [
                "1" if (flip and v == 0) or (not flip and v == 1) else "0" for v in row
            ]
            k = "".join(seq)
            freq[k] += 1
            result = max(result, freq[k])
        return result
