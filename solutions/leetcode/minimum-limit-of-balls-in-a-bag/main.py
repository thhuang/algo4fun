class Solution:
    def minimumSize(self, nums: List[int], max_operations: int) -> int:
        l, r = 0, max(nums)  # (l, r]

        def check(mx):
            ops = 0
            for v in nums:
                ops += (v - 1) // mx
            return ops <= max_operations

        while r - l > 1:
            m = l + (r - l) // 2
            if check(m):
                r = m
            else:
                l = m

        return r
