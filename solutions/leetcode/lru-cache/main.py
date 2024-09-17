class Node:

    def __init__(self, val=0, prv=None, nxt=None):
        self.val = val
        self.prv = prv
        self.nxt = nxt


class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.mp = dict()  # {key: Node}

        self.front = Node()  # (key, val)
        self.last = Node()
        self.front.nxt = self.last
        self.last.prv = self.front

        self.size = 0

    def get(self, key: int) -> int:
        if key not in self.mp:
            return -1

        u = self.mp[key]

        self.remove(u)
        self.pushfront(u)

        return u.val[1]

    def put(self, key: int, value: int) -> None:
        if key in self.mp:
            u = self.mp[key]
            del self.mp[key]
            self.remove(u)

        u = Node((key, value))
        self.mp[key] = u
        self.pushfront(u)

        if self.size > self.cap:
            del self.mp[self.last.prv.val[0]]
            self.remove(self.last.prv)

    def remove(self, u):
        prv, nxt = u.prv, u.nxt
        prv.nxt = nxt
        nxt.prv = prv
        self.size -= 1

    def pushfront(self, u):
        u.prv, u.nxt = self.front, self.front.nxt
        u.prv.nxt, u.nxt.prv = u, u
        self.size += 1


class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1

        self.cache.move_to_end(key)

        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
            self.cache.popitem()

        self.cache[key] = value

        if len(self.cache) > self.cap:
            self.cache.popitem(last=False)


class LRUCache:

    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.cap = capacity

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        self.cache[key] = value
        self.cache.move_to_end(key)
        if len(self.cache) > self.cap:
            self.cache.popitem(last=False)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
