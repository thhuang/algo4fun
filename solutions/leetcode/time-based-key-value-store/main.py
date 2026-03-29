class Store:

    def __init__(self) -> None:
        self.tv = []

    def append(self, v: int, t: int) -> None:
        self.tv.append((t, v))

    def get(self, t: int) -> str:
        if len(self.tv) == 0:
            return ""

        l, r = -1, len(self.tv)  # [l,r)
        while r - l > 1:
            m = (l + r) // 2
            if self.tv[m][0] <= t:
                l = m
            else:
                r = m

        return "" if l == -1 else self.tv[l][1]


class TimeMap:

    def __init__(self) -> None:
        self.kv = defaultdict(lambda: Store())

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.kv[key].append(value, timestamp)

    def get(self, key: str, timestamp: int) -> str:
        return self.kv[key].get(timestamp)


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
