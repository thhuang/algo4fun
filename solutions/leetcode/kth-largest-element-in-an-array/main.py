class Solution:

    def findKthLargest(self, nums: List[int], k: int) -> int:
        n = len(nums)

        def partition(l: int, r: int, t: int) -> int:
            nums[r], nums[t] = nums[t], nums[r]
            p = l
            for i in range(l, r):
                if nums[i] > nums[r]:
                    nums[i], nums[p] = nums[p], nums[i]
                    p += 1
            nums[p], nums[r] = nums[r], nums[p]
            return p

        l = 0
        r = n - 1
        i = 0
        while l <= r and i <= sqrt(n) + 1:
            m = l + (r - l) // 2
            m = partition(l, r, m)
            if m < k:
                l = m + 1
            else:
                r = m - 1
            i += 1

        return nums[r]
