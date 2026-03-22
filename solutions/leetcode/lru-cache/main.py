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


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)


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


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)


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


class Node:

    def __init__(self, key: int = -1, value: int = -1) -> None:
        self.key = key
        self.value = value
        self.prv = None
        self.nxt = None


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head = Node()
        self.tail = Node()
        self.head.nxt = self.tail
        self.tail.prv = self.head
        self.key_to_node = {}

    def get(self, key: int) -> int:
        # check if the key exists
        #   false: return -1
        #   true:  move the node to the front then return the value

        if key not in self.key_to_node:
            return -1

        self._move_node_to_front(key)

        return self.key_to_node[key].value

    def put(self, key: int, value: int) -> None:
        # check if the key exists
        #   true: remove the node
        #
        # add the node to the front
        #
        # check if the size > capacity
        #   true: remove the last node

        if key in self.key_to_node:
            self._remove_node(key)

        self._add_front(key, value)

        if len(self.key_to_node) > self.capacity:
            self._remove_node(self.tail.prv.key)

    def _remove_node(self, key: int) -> None:
        node = self.key_to_node[key]
        prv, nxt = node.prv, node.nxt
        prv.nxt, nxt.prv = node.nxt, node.prv
        del self.key_to_node[key]

    def _add_front(self, key: int, value: int) -> None:
        node = Node(key=key, value=value)
        prv, nxt = self.head, self.head.nxt
        prv.nxt, nxt.prv = node, node
        node.prv, node.nxt = prv, nxt
        self.key_to_node[key] = node

    def _move_node_to_front(self, key: int) -> None:
        value = self.key_to_node[key].value
        self._remove_node(key)
        self._add_front(key, value)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)


class Node:

    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.prv = None
        self.nxt = None


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity

        # head <-> [nodes] <-> tail
        self.head = Node()
        self.tail = Node()
        self.head.nxt, self.tail.prv = self.tail, self.head

        self.key_to_node = {}

    def get(self, key: int) -> int:
        # check if the key exists
        #   false: return -1
        #   true: move the node to front and return the value
        if key not in self.key_to_node:
            return -1

        self._move_front(key)

        return self.key_to_node[key].value

    def put(self, key: int, value: int) -> None:
        # check if the key exists
        #   true: remove the node
        #
        # add the node to front
        #
        # check if size > capacity
        #   true: remove the last node

        if key in self.key_to_node:
            self._remove(key)

        self._add_front(key, value)

    def _move_front(self, key: int) -> None:
        value = self.key_to_node[key].value
        self._remove(key)
        self._add_front(key, value)

    def _remove(self, key: int) -> None:
        node = self.key_to_node[key]

        # from: a <-> node <-> b
        # to:   a <-> b
        a, b = node.prv, node.nxt
        a.nxt, b.prv = b, a
        node.prv, node.nxt = None, None

        del self.key_to_node[key]

    def _add_front(self, key: int, value: int) -> None:
        node = Node(key=key, value=value)

        # from: a(head) <-> b
        # to:   a(head) <-> node <-> b
        a, b = self.head, self.head.nxt
        a.nxt, b.prv = node, node
        node.prv, node.nxt = a, b

        self.key_to_node[key] = node

        if len(self.key_to_node) > self.capacity:
            self._remove(self.tail.prv.key)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
