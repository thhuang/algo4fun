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
    int maxPathSum(TreeNode* root) {
        int result = root->val;

        function<int(TreeNode*)> dfs = [&](TreeNode* u) -> int {
            if (!u) return 0;

            int v = u->val;
            int l = max(0, dfs(u->left));
            int r = max(0, dfs(u->right));

            result = max(result, v + l + r);

            return v + max(l, r);
        };

        dfs(root);

        return result;
    }
};
