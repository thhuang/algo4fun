class Solution:

    class Node:

        def __init__(self):
            self.children = [None for i in range(26)]
            self.suggestions = []

    def insert(self, root, s, idx):
        p = root
        for c in s:
            i = ord(c) - ord('a')
            if p.children[i] is None:
                p.children[i] = self.Node()
            p = p.children[i]
            if len(p.suggestions) < 3:
                p.suggestions.append(idx)

    def suggestedProducts(self, products: List[str],
                          searchWord: str) -> List[List[str]]:
        products.sort()
        root = self.Node()

        for i, product in enumerate(products):
            self.insert(root, product, i)

        result = [[] for _ in range(len(searchWord))]
        p = root

        for k, c in enumerate(searchWord):
            p = p.children[ord(c) - ord('a')]
            if p is None:
                break
            for j in p.suggestions:
                result[k].append(products[j])

        return result
