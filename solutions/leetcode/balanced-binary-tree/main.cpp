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
    bool isBalanced(TreeNode* root) {
        bool result = true;
        function<int(TreeNode*)> maxHeight = [&](TreeNode* u) -> int {
            if (u == nullptr) return 0;
            int l = maxHeight(u->left);
            int r = maxHeight(u->right);
            if (abs(l - r) > 1) result = false;
            return max(l, r) + 1;
        };
        maxHeight(root);
        return result;
    }
};
