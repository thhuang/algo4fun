class Solution:

    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        odds = [-1]
        for i, v in enumerate(nums):
            if v % 2 == 1:
                odds.append(i)
        odds.append(len(nums))

        result = 0
        for i in range(k, len(odds) - 1):
            result += (odds[i + 1] - odds[i]) * (odds[i - k + 1] - odds[i - k])

        return result
