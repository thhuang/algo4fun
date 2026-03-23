# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        result = []

        def preorder(u: Optional[TreeNode]) -> None:
            if u is None:
                result.append(",")
                return

            result.append(f",{u.val}")
            preorder(u.left)
            preorder(u.right)

        preorder(root)

        return "".join(result)[1:]

    def deserialize(self, data: str) -> Optional[TreeNode]:
        nodes = data.split(",")

        p = 0

        def construct() -> Optional[TreeNode]:
            nonlocal p

            if nodes[p] == "":
                p += 1
                return None

            u = TreeNode(int(nodes[p]))
            p += 1

            u.left = construct()
            u.right = construct()

            return u

        return construct()


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        result = []

        def preorder(u: Optional[TreeNode]) -> None:
            if u is None:
                result.append(",")
                return

            result.append(f",{u.val}")
            preorder(u.left)
            preorder(u.right)

        preorder(root)

        return "".join(result)[1:]

    def deserialize(self, data: str) -> Optional[TreeNode]:
        tokens = iter(data.split(","))

        def construct() -> Optional[TreeNode]:
            token = next(tokens)

            if token == "":
                return None

            u = TreeNode(int(token))
            u.left = construct()
            u.right = construct()

            return u

        return construct()


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        result = []

        q = deque([root])

        while q:
            u = q.popleft()

            if u is None:
                result.append(",")
                continue

            result.append(f",{u.val}")
            q.append(u.left)
            q.append(u.right)

        return "".join(result)[1:]

    def deserialize(self, data: str) -> Optional[TreeNode]:
        if data == "":
            return None

        tokens = iter(data.split(","))

        token = next(tokens)
        root = TreeNode(int(token))

        q = [root]

        while q:
            nq = []

            for u in q:
                l = next(tokens)
                if l:
                    u.left = TreeNode(int(l))
                    nq.append(u.left)

                r = next(tokens)
                if r:
                    u.right = TreeNode(int(r))
                    nq.append(u.right)

            q = nq

        return root


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
