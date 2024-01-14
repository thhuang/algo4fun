import heapq


class SmallestInfiniteSet:

    def __init__(self):
        self.mn = 1
        self.pq = list()
        self.exists = set()

    def popSmallest(self) -> int:
        if len(self.pq) == 0:
            self.mn += 1
            return self.mn - 1

        v = heapq.heappop(self.pq)
        print(v in self.exists)
        self.exists.remove(v)
        return v

    def addBack(self, num: int) -> None:
        if num >= self.mn or num in self.exists:
            return

        heapq.heappush(self.pq, num)
        self.exists.add(num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
