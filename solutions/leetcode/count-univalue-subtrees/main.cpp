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
    int mt = 1e9;
    int no = 1e9 + 1;

   public:
    int countUnivalSubtrees(TreeNode* root) {
        int result = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* u) -> int {
            if (u == nullptr) return mt;

            int v = u->val;

            int l = dfs(u->left);
            int r = dfs(u->right);

            if (l != mt && l != v) return no;
            if (r != mt && r != v) return no;

            ++result;

            return v;
        };

        dfs(root);

        return result;
    }
};
