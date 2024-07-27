class Solution:

    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        char_to_idx = lambda c: ord(c) - ord("a")

        mat = [[inf for _ in range(26)] for _ in range(26)]
        for u in range(26):
            mat[u][u] = 0
        for u, v, w in zip(original, changed, cost):
            mat[char_to_idx(u)][char_to_idx(v)] = min(mat[char_to_idx(u)][char_to_idx(v)], w)

        for k in range(26):
            for i in range(26):
                for j in range(26):
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j])

        result = 0
        for u, v in zip(source, target):
            result += mat[char_to_idx(u)][char_to_idx(v)]

        return result if result < inf else -1
