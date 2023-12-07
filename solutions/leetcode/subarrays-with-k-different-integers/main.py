class Solution:

    class Window:

        def __init__(self):
            self.num_freq = Counter()
            self.num_count = 0

        def insert(self, v):
            self.num_freq[v] += 1
            if self.num_freq[v] == 1:
                self.num_count += 1

        def remove(self, v):
            self.num_freq[v] -= 1
            if self.num_freq[v] == 0:
                self.num_count -= 1

        def size(self):
            return self.num_count

    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        wl = self.Window()
        wr = self.Window()

        result = 0

        ll = 0
        lr = 0
        for r, v in enumerate(nums):
            wl.insert(v)
            wr.insert(v)

            while wl.size() > k:
                wl.remove(nums[ll])
                ll += 1

            while wr.size() >= k:
                wr.remove(nums[lr])
                lr += 1

            result += lr - ll

        return result
