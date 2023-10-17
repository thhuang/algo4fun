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
   public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* result = nullptr;

        function<void(TreeNode*)> upsideDown = [&](TreeNode* u) -> void {
            if (u == nullptr || u->left == nullptr) {
                result = u;
                return;
            }
            upsideDown(u->left);
            auto l = u->left;
            auto r = u->right;
            l->left = r;
            l->right = u;
            u->left = u->right = nullptr;
        };
        upsideDown(root);

        return result;
    }
};
