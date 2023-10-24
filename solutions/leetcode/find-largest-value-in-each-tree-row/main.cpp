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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* u, int row) -> void {
            if (u == nullptr) return;
            if (result.size() == row) {
                result.push_back(u->val);
            } else {
                result[row] = max(result[row], u->val);
            }
            dfs(u->left, row + 1);
            dfs(u->right, row + 1);
        };
        dfs(root, 0);
        return result;
    }
};
