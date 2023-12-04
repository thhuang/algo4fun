class Solution:

    def getAverages(self, nums: List[int], k: int) -> List[int]:
        result = [-1 for _ in range(len(nums))]

        window = k * 2 + 1
        total = 0

        for r in range(len(nums)):
            i = r - k
            l = i - k

            total += nums[r]

            if l < 0:
                continue

            result[i] = total // window
            total -= nums[l]

        return result
