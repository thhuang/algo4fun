# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        height = defaultdict(int)

        def inorder(u: Optional[TreeNode], current_height: int, max_height: int, left_to_right: bool) -> int:
            nonlocal height

            if u is None:
                return max_height

            height[u.val] = max(height[u.val], max_height)
            max_height = max(max_height, current_height)

            children = (u.left, u.right) if left_to_right else (u.right, u.left)
            max_height = inorder(children[0], current_height + 1, max_height, left_to_right)
            max_height = inorder(children[1], current_height + 1, max_height, left_to_right)

            return max_height

        inorder(root, 0, 0, True)
        inorder(root, 0, 0, False)

        return [height[u] for u in queries]
