class UnionFind:

    def __init__(self, n: int) -> None:
        self.group = [i for i in range(n)]
        self.rank = [0] * n
        self.group_count = n

    def find(self, k) -> int:
        if k == self.group[k]:
            return k
        self.group[k] = self.find(self.group[k])
        return self.group[k]

    def unite(self, a: int, b: int) -> bool:
        ga = self.find(a)
        gb = self.find(b)

        if ga == gb:
            return False

        if self.rank[ga] < self.rank[gb]:
            self.group[ga] = gb
        elif self.rank[gb] < self.rank[ga]:
            self.group[gb] = ga
        else:
            self.group[gb] = ga
            self.rank[ga] += 1

        self.group_count -= 1

        return True

    def isUnited(self) -> bool:
        return self.group_count == 1


class Solution:

    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        alice = UnionFind(n)
        bob = UnionFind(n)

        result = 0

        for t, a, b in edges:
            if t != 3:
                continue
            if not alice.unite(a - 1, b - 1):
                result += 1
            bob.unite(a - 1, b - 1)

        for t, a, b in edges:
            if t == 1:
                if not alice.unite(a - 1, b - 1):
                    result += 1
            elif t == 2:
                if not bob.unite(a - 1, b - 1):
                    result += 1

        return result if alice.isUnited() and bob.isUnited() else -1
