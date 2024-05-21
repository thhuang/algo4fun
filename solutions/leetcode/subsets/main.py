class Solution:

    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []

        subset = []

        def process(i):
            nonlocal result

            if i == len(nums):
                result.append(subset.copy())
                return

            process(i + 1)
            subset.append(nums[i])
            process(i + 1)
            subset.pop()

        process(0)

        return result
