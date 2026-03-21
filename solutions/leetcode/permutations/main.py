class Solution:

    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 0:
            return [[]]

        result = []

        for i in range(len(nums)):
            for p in self.permute(nums[:i] + nums[i + 1:]):
                result.append([nums[i]] + p)

        return result


class Solution:

    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []

        def search(i: int) -> None:
            if i == len(nums):
                result.append(nums.copy())
                return

            for j in range(i, len(nums)):
                nums[i], nums[j] = nums[j], nums[i]
                search(i + 1)
                nums[i], nums[j] = nums[j], nums[i]

        search(0)

        return result
