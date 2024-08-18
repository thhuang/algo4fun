from sortedcontainers import SortedList


class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.sl = SortedList()
        self.k = k
        for v in nums:
            self.add(v)

    def add(self, val: int) -> int:
        self.sl.add(val)
        if len(self.sl) > self.k:
            self.sl.pop(0)
        return self.sl[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
