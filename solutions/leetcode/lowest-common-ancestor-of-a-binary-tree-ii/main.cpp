/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* root = nullptr;
    bool foundP = false;
    bool foundQ = false;

   public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) return nullptr;

        if (!root) root = node;

        TreeNode* result = nullptr;

        if (node == p) foundP = true, result = node;
        if (node == q) foundQ = true, result = node;

        auto l = lowestCommonAncestor(node->left, p, q);
        auto r = lowestCommonAncestor(node->right, p, q);

        if (!result && !l && !r) return nullptr;

        if (root == node && (!foundP || !foundQ)) return nullptr;

        if (l && r) return node;
        if (result) return result;
        return l ? l : r;
    }
};
