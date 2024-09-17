class Solution:

    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        return sorted(points, key=lambda p: p[0] * p[0] + p[1] * p[1])[:k]


class Solution:

    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        n = len(points)

        def dist2(point: List[int]) -> int:
            return point[0] * point[0] + point[1] * point[1]

        def partition(l: int, r: int, t: int) -> int:
            points[t], points[r] = points[r], points[t]
            p = l
            d = dist2(points[r])
            for i in range(l, r):
                if dist2(points[i]) < d:
                    points[i], points[p] = points[p], points[i]
                    p += 1
            points[r], points[p] = points[p], points[r]
            return p

        l, r = 0, n - 1
        while l <= r:
            t = l + (r - l) // 2
            t = partition(l, r, t)
            if t >= k:
                r = t - 1
            else:
                l = t + 1

        return points[:l]


class Solution:

    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:

        def dist2(point: List[int]) -> int:
            return point[0] * point[0] + point[1] * point[1]

        def partition(l, r, t):
            points[t], points[r] = points[r], points[t]
            p = l
            d = dist2(points[r])
            for i in range(l, r):
                if dist2(points[i]) <= d:
                    points[i], points[p] = points[p], points[i]
                    p += 1
            points[r], points[p] = points[p], points[r]
            return p

        l, r = 0, len(points)  # [l, r)
        while r - l > 1:
            m = (l + r) // 2
            m = partition(l, r - 1, m)
            if m >= k:
                r = m
            else:
                l = m

        return points[:r]
