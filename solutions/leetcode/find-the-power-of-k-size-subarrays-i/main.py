class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        if k == 1:
            return nums

        result = []
        consecutive = 1

        for i in range(1, len(nums)):
            if nums[i - 1] + 1 == nums[i]:
                consecutive += 1
            else:
                consecutive = 1

            if i < k - 1:
                continue

            if consecutive >= k:
                result.append(nums[i])
            else:
                result.append(-1)

        return result
