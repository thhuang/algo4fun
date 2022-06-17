/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    enum Status { NotCovered, Covered, WithCamera };

   public:
    int minCameraCover(TreeNode* root) {
        int count = 0;

        function<Status(TreeNode*)> traverse = [&](TreeNode* u) -> Status {
            if (u == nullptr) return Covered;

            auto l = traverse(u->left);
            auto r = traverse(u->right);

            if (l == NotCovered || r == NotCovered) {
                ++count;
                return WithCamera;
            }
            if (l == WithCamera || r == WithCamera) {
                return Covered;
            }
            return NotCovered;
        };

        if (traverse(root) == NotCovered) ++count;
        return count;
    }
};
