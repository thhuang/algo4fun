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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* u) -> int {
            if (!u) return 0;

            int l = dfs(u->left);
            int r = dfs(u->right);

            bool is_leaf = l == 0 && r == 0;
            if (is_leaf) return 1;

            bool has_left_leaf = l == 1;
            if (has_left_leaf) ans += u->left->val;

            return 2;
        };
        dfs(root);
        return ans;
    }
};
