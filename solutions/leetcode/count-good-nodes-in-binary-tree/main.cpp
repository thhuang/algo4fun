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
    int goodNodes(TreeNode* root) {
        int result = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* u, int mx) -> void {
            if (!u) return;
            if (u->val >= mx) ++result;
            mx = max(mx, u->val);
            dfs(u->left, mx);
            dfs(u->right, mx);
        };
        dfs(root, root->val);
        return result;
    }
};

class Solution {
   public:
    int goodNodes(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* u, int mx) -> int {
            if (u == nullptr) return 0;
            int result = 0;
            if (u->val >= mx) ++result;
            mx = max(mx, u->val);
            result += dfs(u->left, mx) + dfs(u->right, mx);
            return result;
        };
        return dfs(root, numeric_limits<int>::min());
    }
};
