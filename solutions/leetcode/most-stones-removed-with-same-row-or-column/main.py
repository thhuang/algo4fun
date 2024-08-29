class Solution:

    def removeStones(self, stones: List[List[int]]) -> int:
        n = len(stones)
        vis = [False] * n

        def dfs(i: int):
            if vis[i]:
                return
            vis[i] = True
            for j in range(n):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    dfs(j)

        result = n
        for i in range(n):
            if not vis[i]:
                dfs(i)
                result -= 1

        return result


class Solution:

    def removeStones(self, stones: List[List[int]]) -> int:
        n = len(stones)
        group, rank = [i for i in range(n)], [0 for _ in range(n)]

        def find(k: int) -> int:
            if k == group[k]:
                return k
            group[k] = find(group[k])
            return group[k]

        def unite(a: int, b: int):
            ga, gb = find(a), find(b)
            if ga == gb:
                return
            if rank[ga] < rank[gb]:
                group[ga] = gb
            elif rank[gb] < rank[ga]:
                group[gb] = ga
            else:
                group[gb] = ga
                rank[ga] += 1

        for i in range(n):
            for j in range(n):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    unite(i, j)

        return n - len(set([find(u) for u in range(n)]))
