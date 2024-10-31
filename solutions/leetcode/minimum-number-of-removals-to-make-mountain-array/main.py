class Solution:

    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)

        left = self.calculateLongestIncreasingSubsequenceLength(nums)

        nums.reverse()
        right = self.calculateLongestIncreasingSubsequenceLength(nums)
        right.reverse()

        result = n
        for l, r in zip(left, right):
            if l > 1 and r > 1:
                result = min(result, n - l - r + 1)

        return result

    def calculateLongestIncreasingSubsequenceLength(
            self, nums: List[int]) -> List[int]:
        result = [1]
        seq = [nums[0]]

        for i in range(1, len(nums)):
            k = bisect.bisect_left(seq, nums[i])
            if k == len(seq):
                seq.append(nums[i])
            else:
                seq[k] = nums[i]

            result.append(len(seq))

        return result
