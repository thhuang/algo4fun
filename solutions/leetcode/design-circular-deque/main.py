class MyCircularDeque:

    def __init__(self, k: int):
        self.data = [None] * (k + 1)
        self.l = 0
        self.r = 0

    def next(self, p: int) -> int:
        return (p + 1) % len(self.data)

    def prev(self, p: int) -> int:
        return (p - 1 + len(self.data)) % len(self.data)

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        self.l = self.prev(self.l)
        self.data[self.l] = value
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        self.data[self.r] = value
        self.r = self.next(self.r)
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        self.l = self.next(self.l)
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        self.r = self.prev(self.r)
        return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.data[self.l]

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.data[self.prev(self.r)]

    def isEmpty(self) -> bool:
        return self.l == self.r

    def isFull(self) -> bool:
        return self.next(self.r) == self.l


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
