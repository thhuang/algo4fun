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
        int result = numeric_limits<int>::min();

        function<int(TreeNode*)> dfs = [&](TreeNode* u) -> int {
            if (!u) return 0;

            int l = max(0, dfs(u->left));
            int r = max(0, dfs(u->right));
            int res = u->val + max(l, r);

            result = max(result, max(res, u->val + l + r));

            return res;
        };

        dfs(root);

        return result;
    }
};
