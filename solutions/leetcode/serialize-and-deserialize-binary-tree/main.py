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
