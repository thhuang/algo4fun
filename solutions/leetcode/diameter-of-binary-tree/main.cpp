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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* u) -> int {
            if (u == nullptr) return 0;
            int l = dfs(u->left);
            int r = dfs(u->right);
            result = max(result, l + r);
            return max(l, r) + 1;
        };
        dfs(root);
        return result;
    }
};
