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
    int pseudoPalindromicPaths(TreeNode* root) {
        unordered_map<int, int> num_count;
        int odd = 0;
        int result = 0;

        function<void(TreeNode*)> dfs = [&](TreeNode* u) -> void {
            int add = -1;
            if (++num_count[u->val] & 1) add = 1;
            odd += add;

            if (!u->left && !u->right) {
                if (odd <= 1) ++result;
            }

            if (u->left) dfs(u->left);
            if (u->right) dfs(u->right);

            --num_count[u->val];
            odd -= add;
        };

        dfs(root);

        return result;
    }
};
