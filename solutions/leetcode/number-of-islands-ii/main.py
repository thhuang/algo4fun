class Solution:

    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        mn = m * n

        group = [i for i in range(mn)]
        rank = [0] * mn
        land = [False] * mn

        def find(k):
            nonlocal group
            if group[k] == k:
                return k
            group[k] = find(group[k])
            return group[k]

        def unite(a, b):
            nonlocal rank
            ga = find(a)
            gb = find(b)
            if ga == gb:
                return False
            if rank[ga] < rank[gb]:
                group[ga] = gb
            elif rank[gb] < rank[ga]:
                group[gb] = ga
            else:
                group[gb] = ga
                rank[ga] += 1
            return True

        def rc2i(r, c):
            return r * n + c

        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

        result = []
        num = 0

        for r, c in positions:
            i = rc2i(r, c)
            if land[i]:
                result.append(num)
                continue

            land[i] = True
            num += 1

            for dr, dc in directions:
                rr, cc = r + dr, c + dc
                if rr < 0 or m <= rr or cc < 0 or n <= cc:
                    continue

                j = rc2i(r + dr, c + dc)
                if not land[j]:
                    continue

                if unite(i, j):
                    num -= 1

            result.append(num)

        return result
