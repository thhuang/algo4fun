class Node:

    def __init__(self, key=-1, val=-1, prv=None, nxt=None):
        self.key = key
        self.val = val
        self.prv = prv
        self.nxt = nxt


class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.head = Node()
        self.tail = Node()
        self.head.nxt = self.tail
        self.tail.prv = self.head
        self.mp = dict()

    def removeNode(self, key):
        u = self.mp[key]
        a, b = u.prv, u.nxt
        a.nxt = b
        b.prv = a
        del self.mp[key]

    def appendNode(self, key: int, value: int):
        a = self.tail.prv
        b = self.tail
        u = Node(key, value, a, b)
        a.nxt = u
        b.prv = u
        self.mp[key] = u

    def moveToEnd(self, key: int):
        val = self.mp[key].val
        self.removeNode(key)
        self.appendNode(key, val)

    def get(self, key: int) -> int:
        if key not in self.mp:
            return -1
        self.moveToEnd(key)
        return self.mp[key].val

    def put(self, key: int, value: int) -> None:
        if key in self.mp:
            self.removeNode(key)
        self.appendNode(key, value)

        if len(self.mp) > self.cap:
            self.removeNode(self.head.nxt.key)


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
