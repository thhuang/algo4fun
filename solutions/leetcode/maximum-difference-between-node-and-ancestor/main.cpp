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
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;

        int result = 0;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* u, int mn,
                                                      int mx) -> void {
            if (u == nullptr) {
                result = max(result, abs(mx - mn));
                return;
            }
            mn = min(mn, u->val);
            mx = max(mx, u->val);
            dfs(u->left, mn, mx);
            dfs(u->right, mn, mx);
        };
        dfs(root, root->val, root->val);

        return result;
    }
};

class Solution {
    const int inf = 1e8;

   public:
    int maxAncestorDiff(TreeNode* root) {
        int result = 0;

        function<pair<int, int>(TreeNode*)> dfs =
            [&](TreeNode* u) -> pair<int, int> {
            if (u == nullptr) return {inf, -inf};

            auto [lmn, lmx] = dfs(u->left);
            auto [rmn, rmx] = dfs(u->right);

            int mn = min(lmn, rmn);
            int mx = max(lmx, rmx);

            result = max(result, max(mx - u->val, u->val - mn));

            return {min(mn, u->val), max(mx, u->val)};
        };

        dfs(root);

        return result;
    }
};
