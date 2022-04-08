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
    bool check(TreeNode* root, int lower, int upper, bool include_lower,
               bool include_upper) {
        if (!root) return true;
        if (root->val < lower || root->val > upper) return false;
        if (!include_lower && root->val == lower) return false;
        if (!include_upper && root->val == upper) return false;
        return check(root->left, lower, root->val, include_lower, false) &&
               check(root->right, root->val, upper, false, include_upper);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, numeric_limits<int>::min(),
                     numeric_limits<int>::max(), true, true);
    }
};
