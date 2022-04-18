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
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        function<TreeNode*(TreeNode*)> inorder =
            [&](TreeNode* node) -> TreeNode* {
            if (!node) return nullptr;
            if (auto res = inorder(node->left); res) return res;
            if (++i == k) return node;
            if (auto res = inorder(node->right); res) return res;
            return nullptr;
        };
        if (auto res = inorder(root); res) return res->val;
        return 0;
    }
};
