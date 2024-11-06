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
