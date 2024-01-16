class RandomizedSet:

    def __init__(self):
        self.val_index = dict()
        self.vals = list()

    def insert(self, val: int) -> bool:
        if val in self.val_index:
            return False
        self.val_index[val] = len(self.vals)
        self.vals.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.val_index:
            return False

        idx = self.val_index[val]
        last_val = self.vals[-1]

        self.val_index[last_val] = idx
        self.vals[idx] = last_val

        self.vals.pop()
        del self.val_index[val]

        return True

    def getRandom(self) -> int:
        return random.choice(self.vals)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
