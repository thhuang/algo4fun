class Solution:

    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()

        def check(k):
            n = 1
            l = 0
            for r in range(1, len(position)):
                if position[r] - position[l] >= k:
                    l = r
                    n += 1
                if n == m:
                    return True
            return False

        l, r = 0, position[-1] + position[0] + 1  # [l, r)
        while r - l > 1:
            mid = (l + r) // 2
            if check(mid):
                l = mid
            else:
                r = mid

        return l
