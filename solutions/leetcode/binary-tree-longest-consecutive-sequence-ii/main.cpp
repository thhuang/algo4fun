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

        function<pair<int, int>(TreeNode*)> dfs =
            [&](TreeNode* u) -> pair<int, int> {
            if (u == nullptr) return {0, 0};

            pair<int, int> r = {1, 1};
            if (u->right) {
                auto [dec, inc] = dfs(u->right);
                if (u->val == u->right->val - 1) r.first = dec + 1;
                if (u->val == u->right->val + 1) r.second = inc + 1;
            }

            pair<int, int> l = {1, 1};
            if (u->left) {
                auto [dec, inc] = dfs(u->left);
                if (u->val == u->left->val - 1) l.first = dec + 1;
                if (u->val == u->left->val + 1) l.second = inc + 1;
            }

            result = max(result,
                         max(r.first + l.second - 1, r.second + l.first - 1));

            return {max(l.first, r.first), max(l.second, r.second)};
        };

        dfs(root);

        return result;
    }
};
