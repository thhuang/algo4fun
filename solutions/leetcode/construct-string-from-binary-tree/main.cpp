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
        function<void(TreeNode*)> preorder = [&](TreeNode* u) -> void {
            for (char c : to_string(u->val)) result.push_back(c);
            if (u->left == nullptr && u->right == nullptr) return;

            result.push_back('(');
            if (u->left != nullptr) preorder(u->left);
            result.push_back(')');

            if (u->right == nullptr) return;
            result.push_back('(');
            preorder(u->right);
            result.push_back(')');
        };
        preorder(root);
        return result;
    }
};
