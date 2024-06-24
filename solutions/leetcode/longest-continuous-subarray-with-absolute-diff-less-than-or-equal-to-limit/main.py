class Solution:

    def longestSubarray(self, nums: List[int], limit: int) -> int:
        result = 0

        minq = deque()
        maxq = deque()

        l = 0
        for r in range(len(nums)):
            while len(minq) > 0 and minq[-1] > nums[r]:
                minq.pop()
            minq.append(nums[r])

            while len(maxq) > 0 and maxq[-1] < nums[r]:
                maxq.pop()
            maxq.append(nums[r])

            while maxq[0] - minq[0] > limit:
                if minq[0] == nums[l]:
                    minq.popleft()
                if maxq[0] == nums[l]:
                    maxq.popleft()
                l += 1

            result = max(result, r - l + 1)

        return result
