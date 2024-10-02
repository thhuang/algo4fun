class Solution:

    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rank = {}
        for v in sorted(arr):
            if v not in rank:
                rank[v] = len(rank) + 1
        return [rank[v] for v in arr]
