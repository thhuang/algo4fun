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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                            TreeNode* target) {
        if (!original) return nullptr;
        if (original == target) return cloned;
        if (auto l = getTargetCopy(original->left, cloned->left, target); l)
            return l;
        if (auto r = getTargetCopy(original->right, cloned->right, target); r)
            return r;
        return nullptr;
    }
};
