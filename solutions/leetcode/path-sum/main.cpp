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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        function<bool(TreeNode*)> dfs = [&](TreeNode* node) -> bool {
            if (!node) return false;
            if (node->left == nullptr && node->right == nullptr) {
                return sum + node->val == targetSum;
            }

            sum += node->val;
            if (dfs(node->left)) return true;
            if (dfs(node->right)) return true;
            sum -= node->val;

            return false;
        };
        return dfs(root);
    }
};

class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right) return root->val == targetSum;
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
