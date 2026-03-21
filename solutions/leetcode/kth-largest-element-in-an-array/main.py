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


class Solution:

    def findKthLargest(self, nums: List[int], k: int) -> int:
        n = len(nums)

        mn, mx = min(nums), max(nums)
        m = mx - mn + 1

        buckets = [0] * m
        for v in nums:
            buckets[v - mn] += 1

        cnt = 0
        for i, v in enumerate(buckets):
            cnt += v
            if n - cnt < k:
                return i + mn

        return mx


class Solution:

    def findKthLargest(self, nums: List[int], k: int) -> int:
        h = nums[:k]
        heapq.heapify(h)
        for v in nums[k:]:
            if v > h[0]:
                heapq.heapreplace(h, v)
        return h[0]


class Solution:

    def findKthLargest(self, nums: List[int], k: int) -> int:

        def partition(l: int, r: int, p: int) -> List[int]:
            ll, rr = l, r
            i = l

            while i <= rr:
                if nums[i] > p:
                    nums[i], nums[ll] = nums[ll], nums[i]
                    ll += 1
                    i += 1

                elif nums[i] < p:
                    nums[i], nums[rr] = nums[rr], nums[i]
                    rr -= 1

                else:
                    i += 1

            return [ll, rr]

        l, r = 0, len(nums) - 1
        while l <= r:
            p = nums[random.randint(l, r)]
            ll, rr = partition(l, r, p)

            if rr < k - 1:
                l = rr + 1
            elif k - 1 < ll:
                r = ll - 1
            else:
                return nums[ll]

        return -1
