class Solution:

    def canSortArray(self, nums: List[int]) -> bool:
        n = len(nums)
        bits = [v.bit_count() for v in nums]

        for _ in range(n):
            for i in range(1, n):
                if nums[i - 1] > nums[i]:
                    if bits[i - 1] != bits[i]:
                        return False
                    nums[i - 1], nums[i] = nums[i], nums[i - 1]
                    bits[i - 1], bits[i] = bits[i], bits[i - 1]

        return True


class Solution:

    def canSortArray(self, nums: List[int]) -> bool:
        n = len(nums)

        prev_max = -float('inf')
        l = 0

        while l < n:
            mn = nums[l]
            mx = nums[l]
            r = l + 1

            while r < n and nums[l].bit_count() == nums[r].bit_count():
                mn = min(mn, nums[r])
                mx = max(mx, nums[r])
                r += 1

            if prev_max > mn:
                return False
            prev_max = mx

            l = r

        return True
