class StockSpanner:

    def __init__(self):
        self.desc = []

    def next(self, price: int) -> int:
        span = 1
        while len(self.desc) > 0 and self.desc[-1][0] <= price:
            span += self.desc.pop()[1]
        self.desc.append((price, span))
        return span


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
