class Solution:

    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [-1 for _ in range(n)]
        desc = []
        for i, v in enumerate(nums):
            while len(desc) > 0 and nums[desc[-1]] < v:
                result[desc[-1]] = nums[i]
                desc.pop()
            desc.append(i)
        for i, v in enumerate(nums):
            while len(desc) > 0 and nums[desc[-1]] < v:
                result[desc[-1]] = nums[i]
                desc.pop()
            if result[i] != -1:
                desc.append(i)
        return result
