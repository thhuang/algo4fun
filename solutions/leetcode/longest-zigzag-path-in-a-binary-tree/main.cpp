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
    int longestZigZag(TreeNode* root) {
        int result = 1;

        function<pair<int, int>(TreeNode*)> dfs =
            [&](TreeNode* u) -> pair<int, int> {
            if (u == nullptr) return {0, 0};
            auto [ll, lr] = dfs(u->left);
            auto [rl, rr] = dfs(u->right);
            result = max(result, max(max(ll, lr + 1), max(rr, rl + 1)));
            return {lr + 1, rl + 1};
        };

        dfs(root);

        return result - 1;
    }
};
