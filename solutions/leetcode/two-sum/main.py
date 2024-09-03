class Solution:

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = dict()
        for i, v in enumerate(nums):
            if target - v in mp:
                return [mp[target - v], i]
            mp[v] = i
        return []
