class Solution:

    def specialArray(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        if n <= nums[0]:
            return n
        for i in range(1, n):
            if nums[i - 1] < n - i <= nums[i]:
                return n - i
        return -1


class Solution:

    def specialArray(self, nums: List[int]) -> int:
        nums.append(-inf)
        n = len(nums)
        nums.sort()
        for i in range(n):
            if nums[i - 1] < n - i <= nums[i]:
                return n - i
        return -1
