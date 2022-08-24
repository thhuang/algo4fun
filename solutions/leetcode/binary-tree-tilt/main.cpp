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
    int findTilt(TreeNode* root) {
        int result = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* u) -> int {
            if (u == nullptr) return 0;
            int l = dfs(u->left);
            int r = dfs(u->right);
            result += abs(l - r);
            return l + r + u->val;
        };
        dfs(root);
        return result;
    }
};
