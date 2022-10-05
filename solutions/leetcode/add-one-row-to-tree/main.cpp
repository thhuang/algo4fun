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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root) return nullptr;
        if (depth == 1) return new TreeNode(val, root, nullptr);
        function<void(TreeNode * u, int d)> dfs = [&](TreeNode* u,
                                                      int d) -> void {
            if (!u) return;
            if (d + 1 == depth) {
                u->left = new TreeNode(val, u->left, nullptr);
                u->right = new TreeNode(val, nullptr, u->right);
                return;
            }
            dfs(u->left, d + 1);
            dfs(u->right, d + 1);
        };
        dfs(root, 1);
        return root;
    }
};
