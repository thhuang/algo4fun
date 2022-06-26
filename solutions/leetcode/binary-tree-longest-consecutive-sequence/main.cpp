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
    int longestConsecutive(TreeNode* root) {
        int result = 1;

        function<int(TreeNode*)> dfs = [&](TreeNode* u) -> int {
            if (u == nullptr) return 0;

            int path = 1;
            if (int v = dfs(u->right); v && u->val + 1 == u->right->val) {
                path = max(path, v + 1);
            }
            if (int v = dfs(u->left); v && u->val + 1 == u->left->val) {
                path = max(path, v + 1);
            }
            result = max(result, path);

            return path;
        };

        dfs(root);

        return result;
    }
};
