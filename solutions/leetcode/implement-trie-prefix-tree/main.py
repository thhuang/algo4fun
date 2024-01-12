class Trie:

    class Node:

        def __init__(self):
            self.children = dict()
            self.is_end = False

    def __init__(self):
        self.root = self.Node()

    def insert(self, word: str) -> None:
        p = self.root
        for c in word:
            if c not in p.children:
                p.children[c] = self.Node()
            p = p.children[c]
        p.is_end = True

    def search(self, word: str) -> bool:
        node = self.find(word)
        if node is None:
            return False
        return node.is_end

    def startsWith(self, prefix: str) -> bool:
        return self.find(prefix) is not None

    def find(self, s: str) -> 'Optional[Node]':
        p = self.root
        for c in s:
            if c not in p.children:
                return None
            p = p.children[c]
        return p


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
