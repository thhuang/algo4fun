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
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* result = nullptr;
        TreeNode* u = root;
        while (u != nullptr) {
            if (u->val > p->val) {
                if (result == nullptr || result->val > u->val) {
                    result = u;
                }
                u = u->left;
            } else {
                u = u->right;
            }
        }
        return result;
    }
};
