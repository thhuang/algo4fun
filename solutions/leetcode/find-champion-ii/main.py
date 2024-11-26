class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        champion = set(range(n))
        for _, b in edges:
            if b in champion:
                champion.remove(b)
        return champion.pop() if len(champion) == 1 else -1
