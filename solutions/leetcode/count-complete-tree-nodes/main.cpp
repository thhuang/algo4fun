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
    int countNodes(TreeNode* root) {
        int l = 0;
        TreeNode* left = root;
        while (left) left = left->left, ++l;

        int r = 0;
        TreeNode* right = root;
        while (right) right = right->right, ++r;

        if (l == r) return (1 << l) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
