class Solution:

    def sortArray(self, nums: List[int]) -> List[int]:

        def sort(l, r):
            if r <= l:
                return

            m = (l + r) // 2
            sort(l, m)
            sort(m + 1, r)

            result = []

            i, j = l, m + 1
            while i <= m and j <= r:
                if nums[i] < nums[j]:
                    result.append(nums[i])
                    i += 1
                else:
                    result.append(nums[j])
                    j += 1

            if i <= m:
                result += nums[i:m + 1]
            else:
                result += nums[j:r + 1]

            nums[l:r + 1] = result[:]

        sort(0, len(nums) - 1)

        return nums


class Solution:

    def sortArray(self, nums: List[int]) -> List[int]:
        l = min(nums)
        r = max(nums)
        buckets = [0] * (r - l + 1)
        for v in nums:
            buckets[v - l] += 1
        result = []
        for i, v in enumerate(buckets):
            for _ in range(v):
                result.append(l + i)
        return result
