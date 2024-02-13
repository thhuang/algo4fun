class Solution:

    def minAreaRect(self, points: List[List[int]]) -> int:

        rows = defaultdict(lambda: [])
        for x, y in points:
            rows[y].append(x)

        rows = sorted([(y, sorted(xs)) for y, xs in rows.items()])

        result = inf
        dp = defaultdict(lambda: -inf)

        for y, xs in rows:
            if len(xs) < 2:
                continue

            for i in range(len(xs)):
                for j in range(i + 1, len(xs)):
                    l, r = xs[i], xs[j]

                    w = r - l
                    h = y - dp[(l, r)]
                    result = min(result, w * h)

                    dp[(l, r)] = y

        return result if result < inf else 0
