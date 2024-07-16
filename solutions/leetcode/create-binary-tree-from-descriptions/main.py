# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        mp = {}
        for parent, child, is_left in descriptions:
            if parent not in mp:
                mp[parent] = [TreeNode(parent), False]
            if child not in mp:
                mp[child] = [TreeNode(child), True]

            mp[child][1] = True

            if is_left:
                mp[parent][0].left = mp[child][0]
            else:
                mp[parent][0].right = mp[child][0]

        for _, [u, has_parent] in mp.items():
            if not has_parent:
                return u

        return None
