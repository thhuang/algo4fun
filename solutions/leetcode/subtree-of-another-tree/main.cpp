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
    bool check(TreeNode* t0, TreeNode* t1) {
        if (t0 == nullptr && t1 == nullptr) return true;
        if (t0 == nullptr || t1 == nullptr) return false;
        if (t0->val != t1->val) return false;
        return check(t0->left, t1->left) && check(t0->right, t1->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) return true;

        function<bool(TreeNode*)> dfs = [&](TreeNode* node) -> bool {
            if (node == nullptr) return false;
            if (node->val == subRoot->val && check(node, subRoot)) return true;
            return dfs(node->left) || dfs(node->right);
        };

        return dfs(root);
    }
};
