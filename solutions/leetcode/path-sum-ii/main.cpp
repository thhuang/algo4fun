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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};

        vector<vector<int>> result;
        vector<int> path = {root->val};
        int target = targetSum - root->val;
        function<void(TreeNode*)> dfs = [&](TreeNode* u) -> void {
            if (u->left == nullptr && u->right == nullptr) {
                if (target == 0) result.push_back(path);
                return;
            }
            if (u->left) {
                path.push_back(u->left->val);
                target -= u->left->val;
                dfs(u->left);
                target += u->left->val;
                path.pop_back();
            }
            if (u->right) {
                path.push_back(u->right->val);
                target -= u->right->val;
                dfs(u->right);
                target += u->right->val;
                path.pop_back();
            }
        };

        dfs(root);

        return result;
    }
};
