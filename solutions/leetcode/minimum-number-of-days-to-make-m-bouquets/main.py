class Solution:

    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if m * k > len(bloomDay):
            return -1

        def check(day):
            bouquets = 0
            adj = 0
            for b in [v <= day for v in bloomDay]:
                adj = adj + 1 if b else 0
                if adj == k:
                    adj = 0
                    bouquets += 1
                if bouquets == m:
                    return True
            return False

        l, r = -1, max(bloomDay)  # (l, r]
        while r - l > 1:
            v = (l + r) // 2
            if check(v):
                r = v
            else:
                l = v

        return r
