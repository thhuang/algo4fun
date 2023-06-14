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
    int getMinimumDifference(TreeNode* root) {
        int result = 1e5;
        int p = -1e5;
        function<void(TreeNode*)> inorder = [&](TreeNode* u) -> void {
            if (u == nullptr) return;
            inorder(u->left);
            result = min(result, u->val - p);
            p = u->val;
            inorder(u->right);
        };
        inorder(root);
        return result;
    }
};
