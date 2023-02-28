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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        vector<TreeNode *> result;
        unordered_map<string, int> cnt;

        function<string(TreeNode *)> dfs = [&](TreeNode *u) -> string {
            if (u == nullptr) return "()";
            string l = dfs(u->left);
            string r = dfs(u->right);
            string s = "(" + to_string(u->val) + l + r + ")";
            if (++cnt[s] == 2) result.push_back(u);
            return s;
        };
        dfs(root);

        return result;
    }
};
