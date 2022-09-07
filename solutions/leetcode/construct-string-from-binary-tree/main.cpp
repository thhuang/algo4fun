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
    string tree2str(TreeNode* root) {
        string result;
        function<void(TreeNode*)> dfs = [&](TreeNode* u) -> void {
            result += to_string(u->val);
            if (!u->left && !u->right) return;

            if (u->left || u->right) {
                result += "(";
                if (u->left) dfs(u->left);
                result += ")";
            }

            if (u->right) {
                result += "(";
                dfs(u->right);
                result += ")";
            }
        };
        dfs(root);
        return result;
    }
};
