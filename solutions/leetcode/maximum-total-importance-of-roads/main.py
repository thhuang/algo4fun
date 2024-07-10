class Solution:

    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        degree = [0] * n
        for u, v in roads:
            degree[u] += 1
            degree[v] += 1

        result = 0
        for i, d in enumerate(sorted(degree)):
            result += d * (i + 1)

        return result
