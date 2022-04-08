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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> nums;
        function<bool(TreeNode*)> search = [&](TreeNode* node) -> bool {
            if (!node) return false;
            if (nums.count(k - node->val)) return true;
            nums.insert(node->val);
            return search(node->left) || search(node->right);
        };
        return search(root);
    }
};
