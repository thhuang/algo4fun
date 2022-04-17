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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode dummy;
        TreeNode* p = &dummy;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) -> void {
            if (!node) return;
            inorder(node->left);
            p->right = node;
            p = p->right;
            p->left = nullptr;
            inorder(node->right);
        };
        inorder(root);
        return dummy.right;
    }
};
