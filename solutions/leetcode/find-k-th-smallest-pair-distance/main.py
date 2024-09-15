class Solution:

    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)

        def check(d: int) -> bool:
            cnt = 0

            l = 0
            for r in range(1, n):
                while l < r and nums[r] - nums[l] > d:
                    l += 1
                cnt += r - l

            return cnt >= k

        l, r = -1, nums[-1] - nums[0]  # (l, r]
        while r - l > 1:
            m = (l + r) // 2
            if check(m):
                r = m
            else:
                l = m

        return r
