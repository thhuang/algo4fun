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
    int sumNumbers(TreeNode* root) {
        int result = 0;
        function<void(TreeNode*, int prefix)> dfs = [&](TreeNode* u,
                                                        int prefix) -> void {
            int num = prefix * 10 + u->val;
            if (u->left == nullptr && u->right == nullptr) {
                result += num;
                return;
            }
            if (u->left) dfs(u->left, num);
            if (u->right) dfs(u->right, num);
        };
        dfs(root, 0);
        return result;
    }
};

class Solution {
   public:
    int sumNumbers(TreeNode* root) {
        int result = 0;
        int sum = 0;
        function<void(TreeNode*)> dfs = [&](TreeNode* u) -> void {
            sum = sum * 10 + u->val;
            if (!u->left && !u->right) {
                result += sum;
            } else {
                if (u->left) dfs(u->left);
                if (u->right) dfs(u->right);
            }
            sum /= 10;
        };
        dfs(root);
        return result;
    }
};
