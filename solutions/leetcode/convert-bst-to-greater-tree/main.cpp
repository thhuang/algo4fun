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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        function<void(TreeNode*)> rev_inorder = [&](TreeNode* u) -> void {
            if (u == nullptr) return;
            rev_inorder(u->right);
            sum += u->val;
            u->val = sum;
            rev_inorder(u->left);
        };
        rev_inorder(root);
        return root;
    }
};
