class Solution:

    def __init__(self, w: List[int]):
        self.prefix_w = [0]
        for v in w:
            self.prefix_w.append(self.prefix_w[-1] + v)

    def pickIndex(self) -> int:
        v = random.random() * self.prefix_w[-1]
        r = bisect.bisect_right(self.prefix_w, v)
        return min(r - 1, len(self.prefix_w) - 2)


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
