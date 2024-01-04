class Solution:

    def minOperations(self, nums: List[int]) -> int:
        result = 0

        for _, v in Counter(nums).items():
            if v == 1:
                return -1

            result += v // 3
            if v % 3 > 0:
                result += 1

        return result
