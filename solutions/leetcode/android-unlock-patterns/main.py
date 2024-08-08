class Solution:

    def __init__(self):
        self.middle_dots = {
            (1, 3): 2,
            (3, 1): 2,
            (4, 6): 5,
            (6, 4): 5,
            (7, 9): 8,
            (9, 7): 8,
            (1, 7): 4,
            (7, 1): 4,
            (2, 8): 5,
            (8, 2): 5,
            (3, 9): 6,
            (9, 3): 6,
            (1, 9): 5,
            (9, 1): 5,
            (3, 7): 5,
            (7, 3): 5,
        }

    def numberOfPatterns(self, m: int, n: int) -> int:
        if m > n:
            return 0

        result = 0
        vis = set()

        def dfs(u: int):
            nonlocal result
            nonlocal vis

            if len(vis) >= m:
                result += 1

            if len(vis) == n:
                return

            for v in range(1, 10):
                if v in vis:
                    continue
                if (u, v) in self.middle_dots and self.middle_dots[(u, v)] not in vis:
                    continue
                vis.add(v)
                dfs(v)
                vis.remove(v)

        for u in range(1, 10):
            vis.add(u)
            dfs(u)
            vis.remove(u)

        return result


class Solution:

    def __init__(self):
        self.middle_dots = {
            (1, 3): 2,
            (3, 1): 2,
            (4, 6): 5,
            (6, 4): 5,
            (7, 9): 8,
            (9, 7): 8,
            (1, 7): 4,
            (7, 1): 4,
            (2, 8): 5,
            (8, 2): 5,
            (3, 9): 6,
            (9, 3): 6,
            (1, 9): 5,
            (9, 1): 5,
            (3, 7): 5,
            (7, 3): 5,
        }

    def numberOfPatterns(self, m: int, n: int) -> int:
        if m > n:
            return 0

        result = 0
        vis = set()

        def dfs(u: int):
            nonlocal result
            nonlocal vis

            try:
                vis.add(u)

                if len(vis) >= m:
                    result += 1

                if len(vis) == n:
                    return

                for v in range(1, 10):
                    if v in vis:
                        continue
                    if (u, v) in self.middle_dots and self.middle_dots[(u, v)] not in vis:
                        continue
                    dfs(v)

            finally:
                vis.remove(u)

        for u in range(1, 10):
            dfs(u)

        return result
