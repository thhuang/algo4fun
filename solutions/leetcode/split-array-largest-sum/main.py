class Solution:

    def splitArray(self, nums: List[int], k: int) -> int:

        def check(t):
            cnt = 1
            s = 0
            for v in nums:
                s += v
                if s > t:
                    cnt += 1
                    s = v
            return cnt <= k

        l, r = max(nums) - 1, sum(nums)  # (l, r]
        while r - l > 1:
            m = (l + r) // 2
            if check(m):
                r = m
            else:
                l = m

        return r
