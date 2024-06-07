class Solution:

    class Trie:

        class Node:

            def __init__(self):
                self.children = dict()
                self.is_end = False

        def __init__(self):
            self.root = self.Node()

        def insert(self, s):
            p = self.root
            for c in s:
                if c not in p.children:
                    p.children[c] = self.Node()
                p = p.children[c]
            p.is_end = True

        def prefix(self, s):
            p = self.root
            result = []
            for c in s:
                if c not in p.children:
                    return None
                result.append(c)
                p = p.children[c]
                if p.is_end:
                    return "".join(result)
            return None

    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        trie = self.Trie()

        for s in dictionary:
            trie.insert(s)

        result = []
        for s in sentence.split(" "):
            t = trie.prefix(s)
            result.append(t) if t is not None else result.append(s)

        return " ".join(result)
