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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // trim left
        TreeNode dummy(0, root, nullptr);
        TreeNode* p = &dummy;
        while (p->left) {
            if (p->left->val >= low) {
                p = p->left;
            } else {
                p->left = p->left->right;
            }
        }

        // trim right
        dummy.right = dummy.left;
        p = &dummy;
        while (p->right) {
            if (p->right->val <= high) {
                p = p->right;
            } else {
                p->right = p->right->left;
            }
        }

        return dummy.right;
    }
};
