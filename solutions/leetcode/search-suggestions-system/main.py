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


import bisect


class Solution:

    def suggestedProducts(self, products: List[str],
                          searchWord: str) -> List[List[str]]:
        products.sort()

        result = []

        for i in range(len(searchWord)):
            l = bisect.bisect_left(products,
                                   searchWord[0:i + 1],
                                   key=lambda s: s[0:i + 1])
            r = bisect.bisect_right(products,
                                    searchWord[0:i + 1],
                                    key=lambda s: s[0:i + 1])
            r = min(r, l + 3)
            result.append(products[l:r])

        return result
