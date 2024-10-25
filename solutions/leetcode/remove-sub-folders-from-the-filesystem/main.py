class Solution:

    class Node:

        def __init__(self):
            self.children = {}
            self.is_leaf = False

    def removeSubfolders(self, folder: List[str]) -> List[str]:
        root = self.Node()

        def add(path):
            p = root
            for v in path[1:].split("/"):
                if p.is_leaf:
                    return
                if v not in p.children:
                    p.children[v] = self.Node()
                p = p.children[v]

            p.children = {}
            p.is_leaf = True

        result = []
        path = []

        def dfs(p, u):
            nonlocal path
            nonlocal result

            path.append(p)

            if u.is_leaf:
                result.append("/".join(path))
            else:
                for k, v in u.children.items():
                    dfs(k, v)

            path.pop()

        for f in folder:
            add(f)
        dfs("", root)

        return result
