class Solution:

    def subsetXORSum(self, nums: List[int]) -> int:
        result = 0
        curr = 0

        def search(i):
            nonlocal result
            nonlocal curr

            if i == len(nums):
                result += curr
                return

            search(i + 1)
            curr ^= nums[i]
            search(i + 1)
            curr ^= nums[i]

        search(0)

        return result
