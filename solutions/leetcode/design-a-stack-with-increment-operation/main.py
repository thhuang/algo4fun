class CustomStack:

    def __init__(self, max_size: int):
        self.max_size = max_size
        self.data = []
        self.diff = defaultdict(int)

    def push(self, x: int) -> None:
        if len(self.data) == self.max_size:
            return
        self.data.append(x)

    def pop(self) -> int:
        if len(self.data) == 0:
            return -1

        v = self.data.pop()
        i = len(self.data)

        v += self.diff[i]

        self.diff[i - 1] += self.diff[i]
        self.diff[i] = 0

        return v

    def increment(self, k: int, val: int) -> None:
        k = min(k, len(self.data))
        self.diff[k - 1] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
